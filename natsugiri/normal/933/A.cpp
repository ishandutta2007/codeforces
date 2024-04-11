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
int A[2011];

int dp[2011][6];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    memset(dp, 0xc0, sizeof dp);
    dp[0][0] = 0;

    REP (i, N) {
	for (int t=0; t<4;) {
	    if (dp[i][t] >= 0) {
		if (A[i] == 1) amax(dp[i+1][t], dp[i][t] + 1);
		else amax(dp[i+1][t+1], dp[i][t] + 1);

		amax(dp[i+1][t], dp[i][t]);
		amax(dp[i+1][t+1], dp[i][t]);
	    }
	    t++;
	    if (dp[i][t] >= 0) {
		if (A[i] == 1) amax(dp[i+1][t+1], dp[i][t] + 1);
		else amax(dp[i+1][t], dp[i][t] + 1);

		amax(dp[i+1][t], dp[i][t]);
		amax(dp[i+1][t+1], dp[i][t]);
	    }
	    t++;
	}

//	rprintf("%d", dp[i+1], dp[i+1]+4);
    }

    int ans = 0;
    REP (i, N) REP (t, 4) amax(ans, dp[N][t]);
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}