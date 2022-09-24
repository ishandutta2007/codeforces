#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
int A[200111];
int dp[200111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    A[N] = 0;
    memset(dp, 0x3f, sizeof (dp[0]) * (N+5));

    dp[0] = 0;
    REP (i, N) {
	amin(dp[i+2], dp[i] + A[i]);
	amin(dp[i+3], dp[i] + A[i]);
	amin(dp[i+4], dp[i] + A[i] + A[i+1]);
    }

    int ans = min(dp[N], dp[N+1]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}