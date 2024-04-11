#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
int COUNT[1<<9];
pair<LL, int> COST[1<<9][2];
LL COST2[1<<9];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, N) {
	int len, mask = 0;
	scanf("%d", &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    mask |= 1<<x;
	}
	COUNT[mask]++;
    }

    memset(COST, 0x3f, sizeof COST);
    const LL INF = COST[0][0].first;

    REP (i, M) {
	int cst, len, mask = 0;
	scanf("%d%d", &cst, &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    mask |= 1<<x;
	}

	pair<LL, int> key(cst, i);
	if (COST[mask][1] > key) swap(COST[mask][1], key);
	if (COST[mask][0] > COST[mask][1]) swap(COST[mask][0], COST[mask][1]);
    }

    memset(COST2, 0x3f, sizeof COST2);
    REP (s, 1<<9) REP (t, 1<<9) {
	amin(COST2[s|t], COST[s][0].first + COST[t][(s==t?1:0)].first);
    }

    REP (t, 9) REP (s, 1<<9) if (~s>>t&1) COUNT[s|(1<<t)] += COUNT[s];

    int best_mask = 0;
    int best_count = 0;
    LL best_cost = INF;
    REP (s, 1<<9) {
	if (COST2[s] < INF) {
	    if (best_count < COUNT[s] || (best_count == COUNT[s] && best_cost > COST2[s])) {
		best_mask = s;
		best_count = COUNT[s];
		best_cost = COST2[s];
	    }
	}
    }

    REP (s, 1<<9) REP (t, 1<<9) if ((s|t) == best_mask) {
	pair<LL, int> as = COST[s][0], at = COST[t][(s==t?1:0)];
	if (as.first + at.first == best_cost) {
	    int a = as.second;
	    int b = at.second;
	    if (a > b) swap(a, b);
	    printf("%d %d\n", a+1, b+1);
	    return;
	}
    }

    assert(false);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}