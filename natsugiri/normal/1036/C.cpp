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

LL dp[55][4][2];

LL F(LL X) {
    char S[55];
    sprintf(S, "%lld", X);
    int len = strlen(S);
    memset(dp, 0, sizeof dp);
    REP (i, len) {
	// 0
	REP (a, 4) {
	    dp[i+1][a][1] += dp[i][a][1];
	    if (S[i] == '0') dp[i+1][a][0] += dp[i][a][0];
	    else dp[i+1][a][1] += dp[i][a][0];
	}
	REP (a, 3) {
	    for (int c=1; c<=9; c++) {
		dp[i+1][a+1][1] += dp[i][a][1];
		if (S[i]-'0' > c) dp[i+1][a+1][1] += dp[i][a][0];
		else if (S[i]-'0' == c) dp[i+1][a+1][0] += dp[i][a][0];
	    }
	}

	if (i == 0) {
	    dp[1][1][1] += S[0]-'0'-1;
	    dp[1][1][0] += 1;
	} else {
	    dp[i+1][1][1] += 9;
	}
    }
    LL ans = 0;
    REP (a, 4) REP (b, 2)
	ans += dp[len][a][b];
    return ans;
}


void MAIN() {
    LL L, R;
    scanf("%lld%lld", &L, &R);
    LL ans = F(R) - F(L-1);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}