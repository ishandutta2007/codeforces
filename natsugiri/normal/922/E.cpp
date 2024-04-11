#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int W, B, X;
int cap[1011], cost[1011];

LL dp[10011];
int cnt = 0;

void run(int unit, LL cst) {
    cst *= unit;
    for (int j=cnt; j>=0; j--) if (dp[j] >= cst) {
	amax(dp[j+unit], dp[j] - cst);
    }
}

void MAIN() {
    scanf("%d%d%d%d", &N, &W, &B, &X);
    REP (i, N) scanf("%d", cap+i);
    REP (i, N) scanf("%d", cost+i);

    memset(dp, 0xc0, sizeof dp);

    dp[0] = W;
    REP (i, N) {
	int unit = 1, rest = cap[i];
	while (unit <= rest) {
	    run(unit, cost[i]);
	    cnt += unit;
	    rest -= unit;
	    unit *= 2;
	}
	if (rest) {
	    run(rest, cost[i]);
	    cnt += rest;
	}

	for (int j=cnt; j>=0; j--) if (dp[j] >= 0) {
	    dp[j] = min(W + (LL)j * B, dp[j] + X);
	}
    }

    int ans = 0;
    for (int j=cnt; j>=0; j--) if (dp[j] >= 0) {
	ans = j;
	break;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}