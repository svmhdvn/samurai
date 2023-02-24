#ifndef _BUILD_H_
#define _BUILD_H_

#define EXPLAIN(fmt, ...) \
	do { \
		if (buildopts.flags & BUILDOPT_EXPLAIN) { \
			warn("explain " fmt, __VA_ARGS__); \
		} \
	} while (0)

struct node;

struct buildoptions {
	const char *statusfmt;
	size_t maxjobs, maxfail;
	double maxload;
	enum {
		BUILDOPT_VERBOSE = 1 << 0,
		BUILDOPT_EXPLAIN = 1 << 1,
		BUILDOPT_KEEP_DEP_FILE = 1 << 2,
		BUILDOPT_KEEP_RSP = 1 << 3,
		BUILDOPT_DRYRUN = 1 << 4,
	} flags;
};

extern struct buildoptions buildopts;

/* reset state, so a new build can be executed */
void buildreset(void);
/* schedule a particular target to be built */
void buildadd(struct node *);
/* execute rules to build the scheduled targets */
void build(void);

#endif
