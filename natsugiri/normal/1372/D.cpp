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

int N;
int A[200011];
LL dp[200011][2][2];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0xc0, sizeof dp);
    dp[1][1][0] = A[0];
    dp[1][0][0] = 0;
    for (int i=1; i<N; i++) {
	amax(dp[i+1][1][0], dp[i][0][0] + A[i]);
	amax(dp[i+1][1][1], dp[i][0][1] + A[i]);
	amax(dp[i+1][1][1], dp[i][1][0] + A[i]);
	amax(dp[i+1][0][0], dp[i][1][0]);
	amax(dp[i+1][0][1], dp[i][1][1]);
    }

    LL ans = max({dp[N][0][1], dp[N][1][0], dp[N][1][1]});
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}