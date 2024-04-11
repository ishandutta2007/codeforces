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
char S[100011];
LL A[100011];

LL dp[100011][4];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    REP (i, N) scanf("%lld", A+i);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    REP (i, N) {
	REP (t, 4) {
	    if (S[i] == "hard"[t]) {
		if (t < 3) amin(dp[i+1][t+1], dp[i][t]);
		amin(dp[i+1][t], dp[i][t] + A[i]);
	    } else {
		amin(dp[i+1][t], dp[i][t]);
	    }
	}
    }

    LL ans = dp[N][0];
    REP (t, 4) amin(ans, dp[N][t]);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}