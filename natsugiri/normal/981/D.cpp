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

int N, K;
LL A[55];
LL sums[55];

bool dp[55][55];


void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N) sums[i+1] = sums[i] + A[i];


    LL mask = 0;
    for (int t=60; t--;) {
	LL guess = mask | (1LL<<t);

	memset(dp, 0, sizeof dp);
	dp[0][0] = true;
	REP (k, K) REP (i, N) if (dp[k][i]) {
	    for (int j=i+1; j<=N; j++) if (((sums[j]-sums[i])&guess) == guess) {
		dp[k+1][j] = true;
	    }
	}

	if (dp[K][N]) mask = guess;
    }

    printf("%lld\n", mask);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}