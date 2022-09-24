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

int N, M;
char F[133][133];
int dp[133][2];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[N-1-i]);

    int ans = 0;
    dp[0][0] = 0;
    dp[0][1] = M+1;
    REP (i, N) {
	int le = M+2, ri = -1;
	REP (j, M+2) if (F[i][j] == '1') {
	    amin(le, j);
	    amax(ri, j);
	}

	if (le <= ri) {
	    ans = min(dp[i][0] + ri, dp[i][1] + M + 1 - le);
	    dp[i+1][0] = min(dp[i][0] + ri * 2, dp[i][1] + M + 1) + 1;
	    dp[i+1][1] = min(dp[i][0] + M + 1, dp[i][1] + (M + 1 - le) * 2) + 1;
	} else {
	    dp[i+1][0] = dp[i][0] + 1;
	    dp[i+1][1] = dp[i][1] + 1;
	}
//	printf("%d, %d %d\n", ans, dp[i][0], dp[i][1]);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}