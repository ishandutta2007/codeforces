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
int A[5011];
int dp[5011][5011][2];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0x3f, sizeof dp);
    for (int i=N; i--;) {
	dp[i][i+1][0] = dp[i][i+1][1] = 0;
	if (i+2 <= N) {
	    if (A[i] == A[i+1]) {
		dp[i][i+2][0] = dp[i][i+2][1] = 0;
	    } else {
		dp[i][i+2][0] = dp[i][i+2][1] = 1;
	    }
	}
	for (int j=i+2; j<N; j++) {
	    if (A[i] == A[i+1]) amin(dp[i][j+1][0], dp[i+1][j+1][0]);
	    if (A[j-1] == A[j]) amin(dp[i][j+1][1], dp[i][j][1]);

	    if (A[i] == A[j]) {
		amin(dp[i][j+1][0], dp[i+1][j+1][1]);
		amin(dp[i][j+1][1], dp[i][j][0]);
	    }

	    REP (b, 2) {
		amin(dp[i][j+1][1], dp[i][j][b]+1);
		amin(dp[i][j+1][0], dp[i+1][j+1][b]+1);
	    }
	}
    }

    int ans = 1<<29;
    REP (a, 2) amin(ans, dp[0][N][a]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}