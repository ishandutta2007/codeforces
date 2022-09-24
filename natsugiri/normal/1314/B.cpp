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

int N, K;
int dp[17][1<<16][2][2];
int A[1<<17];

void MAIN() {
    scanf("%d%d", &N, &K);
    VI v;
    REP (i, K) {
	int x;
	scanf("%d", &x);
	x--;
	A[x] = true;
    }
    memset(dp, 0xc0, sizeof dp);
    for (int i=0; i<(1<<N); i+=2) {
	if (A[i] && A[i+1]) {
	    dp[N-1][i/2][1][1] = 1;
	} else if (A[i] || A[i+1]) {
	    dp[N-1][i/2][1][0] = dp[N-1][i/2][0][1] = 1;
	} else {
	    dp[N-1][i/2][0][0] = 0;
	}
    }

    for (int t=N-1; t>=1; t--) {
	for (int i=0; i<(1<<t); i+=2) {
	    REP (a, 2) REP (b, 2) REP (c, 2) REP (d, 2) {
		REP (z, 2) {
		    int Wab = a, Lab = b;
		    if (z) swap(Wab, Lab);
		    int Wcd = c | d;
		    int WLabWcd = Lab | Wcd;
		    int add = (a|b) + (c|d) + (Lab|Wcd);
		    amax(dp[t-1][i/2][Wab][WLabWcd], dp[t][i][a][c] + dp[t][i+1][b][d] + add);
		}
	    }
	}
    }
    int ans = 0;
    REP (a, 2) REP (b, 2) amax(ans, dp[0][0][a][b] + max(a, b));
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}