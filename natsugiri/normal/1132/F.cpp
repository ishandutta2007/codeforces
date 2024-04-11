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
char S[555];
int dp[555][555];
int dp2[555][555];

void MAIN() {
    scanf("%d%s", &N, S);
    N = unique(S, S+N) - S;
    S[N] = 0;

    memset(dp, 0x3f, sizeof dp);
    memset(dp2, 0x3f, sizeof dp2);
    dp[N][N] = dp2[N][N] = 0;

    for (int i=N; i--;) {
	dp[i][i] = 0;
	dp2[i][i] = 0;
	dp[i][i+1] = 1;
	dp2[i][i+1] = 0;

	for (int j=i+2; j<=N; j++) {
	    amin(dp[i][j], dp[i][j-1] + 1);
	    amin(dp[i][j], dp[i+1][j] + 1);

	    amin(dp2[i][j], dp[i+1][j]);
	    amin(dp2[i][j], dp2[i][j-1] + 1);

	    for (int k=i+1; k<j; k++) {
		amin(dp[i][j], dp[i][k] + dp[k][j]);
		if (S[i] == S[k]) amin(dp2[i][j], dp2[i][k] + dp2[k][j]);
	    }

	    amin(dp[i][j], dp2[i][j] + 1);
	}
    }

    printf("%d\n", dp[0][N]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}