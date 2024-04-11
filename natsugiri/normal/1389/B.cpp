#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

int N, K, Z;
int A[100011];

LL dp[100011][6];

void MAIN() {
    scanf("%d%d%d", &N, &K, &Z);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0xc0, sizeof (LL) * 6 * (N+1));
    dp[0][0] = A[0];
    LL ans = -1;

    REP (i, N) REP (a, Z+1) if (dp[i][a] >= 0) {
	int S = i + a * 2;
	if (S == K) {
	    amax(ans, dp[i][a]);
	}
	if (S >= K) continue;

	if (i == N-1) continue;

	amax(dp[i+1][a], dp[i][a] + A[i+1]);
	if (a < Z) {
	    amax(dp[i][a+1], dp[i][a] + A[i+1] + A[i]);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}