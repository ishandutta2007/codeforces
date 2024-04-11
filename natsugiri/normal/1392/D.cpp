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
int dp[200011];

int solve(char S[]) {
    memset(dp, 0x3f, sizeof (dp[0]) * (N+1));
    dp[0] = 0;
    REP (i, N) {
	amin(dp[i+2], dp[i] + (S[i] != 'R'? 1: 0) + (S[i+1] != 'L'? 1: 0));
	amin(dp[i+3], dp[i] + (S[i] != 'R'? 1: 0) + (S[i+2] != 'L'? 1: 0));
	amin(dp[i+4], dp[i]
		+ (S[i  ] != 'R'? 1: 0)
		+ (S[i+1] != 'R'? 1: 0)
		+ (S[i+2] != 'L'? 1: 0)
		+ (S[i+3] != 'L'? 1: 0));
    }
    
    return dp[N];
}

char S[200111];


void MAIN() {
    scanf("%d%s", &N, S);
    REP (i, 4) S[N+i] = S[i];

    int ans = solve(S);
    amin(ans, solve(S+1));
    amin(ans, solve(S+2));
    amin(ans, solve(S+3));

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}