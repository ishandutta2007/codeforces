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

int N;
int A[111];
int dp[111][111][111][2];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int zero = N/2, one = N-zero;
    REP (i, N) {
	if (A[i] > 0) {
	    if (A[i] % 2 == 0) zero--;
	    else one--;
	}
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    REP (i, N) {
	if (A[i] == 0) {
	    REP (z, zero+1) REP (o, one+1) {
		if (z < zero) {
		    REP (t, 2) amin(dp[i+1][z+1][o][0], dp[i][z][o][t] + t);
		}
		if (o < one) {
		    REP (t, 2) amin(dp[i+1][z][o+1][1], dp[i][z][o][t] + 1 - t);
		}
	    }
	} else if (A[i] % 2 == 0) {
	    REP (z, zero+1) REP (o, one+1) {
		REP (t, 2) amin(dp[i+1][z][o][0], dp[i][z][o][t] + t);
	    }
	} else {
	    REP (z, zero+1) REP (o, one+1) {
		REP (t, 2) amin(dp[i+1][z][o][1], dp[i][z][o][t] + 1 - t);
	    }
	}
    }

    int ans = min(dp[N][zero][one][0], dp[N][zero][one][1]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}