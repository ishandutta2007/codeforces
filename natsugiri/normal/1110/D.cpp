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
int C[1000111];
int dp[1000111][5][5];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	C[x-1]++;
    }

    memset(dp, 0xc0, sizeof dp);
    dp[0][0][0] = 0;
    REP (i, M+1) REP (a, 5) if (C[i] >= a) {
	REP (b, 5) if (dp[i][a][b] >= 0) {
	    REP (p, 5-b) if (a + p <= C[i]) {
		amax(dp[i+1][b+p][p], dp[i][a][b] + p + (C[i]-a-p)/3);
	    }
	}
    }

    printf("%d\n", dp[M+1][0][0]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}