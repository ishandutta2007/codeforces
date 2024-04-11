#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, M;
char F[411][411];
int H[411][411];

int dp[411][3];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    REP (i, N) REP (j, M) {
	H[i+1][j] = H[i][j] + (F[i][j] - '0');
    }

    int ans = 1<<29;

    for (int y0=0; y0<N; y0++) for (int y1=y0+4; y1<N; y1++) {
	memset(dp, 0x3f, sizeof dp);

	REP (x, M) {
	    int one = H[y1][x] - H[y0+1][x];
	    int zero = (y1 - y0 - 1) - one;
	    int cost = one + (F[y0][x] == '0'? 1: 0) + (F[y1][x] == '0'? 1: 0);

	    amin(ans, dp[x][2] + zero);
	    amin(dp[x+1][2], dp[x][2] + cost);
	    amin(dp[x+1][2], dp[x][1] + cost);
	    amin(dp[x+1][1], dp[x][0] + cost);
	    amin(dp[x+1][0], zero);
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}