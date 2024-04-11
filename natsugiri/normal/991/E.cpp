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

const int NUM = 50;
LL comb[NUM+1][NUM/2+1];
void make_comb() {
    comb[0][0]=1;
    for (int i=1; i<=NUM; i++) {
        comb[i][0]=1;
        for (int j=1; j<=NUM/2; j++) {
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
        }
    }
}

LL nCk(int n, int k) {
    return comb[n][min(k, n-k)];
}

int C[10];

LL dp[11][60];
LL solve() {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    REP (t, 10) {
	if (C[t]) {
	    REP (i, 30) if (dp[t][i]) {
		for (int w=1; w<=C[t]; w++) {
		    dp[t+1][i+w] += dp[t][i] * nCk(i+w, w);
		}
	    }
	} else {
	    REP (i, 30) dp[t+1][i] = dp[t][i];
	}
    }

    LL ans = 0;
    REP (i, 30) ans += dp[10][i];
//    eprintf("%lld\n", ans);
    return ans;
}

void MAIN() {
    make_comb();
    {
	static char S[111];
	scanf("%s", S);
	int n = strlen(S);
	REP (i, n) C[S[i]-'0']++;
    }

    LL ans = solve();
    if (C[0]) {
	C[0]--;
	ans -= solve();
	if (C[0]) {
	    C[0] = 0;
	    ans -= solve();
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}