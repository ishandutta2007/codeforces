#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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
int A[511];

int dp[511][511];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0x3f, sizeof dp);
    for (int L=N-1; L>=0; L--) {
	dp[L][L+1] = -A[L];
	for (int S=L+1; S<N; S++) {
	    for (int R=S+1; R<=N; R++) {
		if (dp[L][S] < 0 && dp[L][S] == dp[S][R]) {
		    dp[L][R] = dp[L][S]-1;
		}
		if (dp[L][R] > 0) {
		    int len = 0;
		    if (dp[L][S] < 0) len++;
		    else len += dp[L][S];

		    if (dp[S][R] < 0) len++;
		    else len += dp[S][R];
		    amin(dp[L][R], len);
		}
	    }
	}
    }

    int ans;
    if (dp[0][N] < 0) ans = 1;
    else ans = dp[0][N];
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}