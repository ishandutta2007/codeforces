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
char S[2][111];
int dp[111][4];

void MAIN() {
    REP (i, 2) scanf("%s", S[i]);
    N = strlen(S[0]);

    memset(dp, 0xc0, sizeof dp);
    dp[0][3] = 0;
    REP (i, N) {
	int mask = 0;
	REP (t, 2) if (S[t][i] == 'X') mask |= 1<<t;

	REP (a, 4) {
	    amax(dp[i+1][mask], dp[i][a]);
	}
	for (int a=1; a<=2; a++) {
	    if (dp[i][a] >= 0 && mask == 0) {
		amax(dp[i+1][3], dp[i][a] + 1);
	    }

	    if (dp[i][0] >= 0 && (mask & a) == 0) {
		amax(dp[i+1][mask|a], dp[i][0] + 1);
	    }
	}
    }

    int ans = *max_element(dp[N], dp[N]+4);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}