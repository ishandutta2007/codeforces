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

const int MAXN = 85;
vector<pair<int, int> > G[MAXN];
int dp[MAXN][MAXN][MAXN];

int N, K, M;

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	if (x != y) {
	    G[x].emplace_back(y, c);
//	    G[y].emplace_back(x, c);
	}
    }

    if (N < K) {
	puts("-1");
	return;
    }
    if (K == 1) {
	puts("0");
	return;
    }

    // 0 .. N+1
    memset(dp, 0x3f, sizeof dp);
    const int INF = dp[0][0][0];
    REP (v, N+2) REP (w, N+2) if (v != w) dp[1][v][w] = 0;

    REP (k, K) {
	REP (v, N+2) EACH (e, G[v]) {
	    if (e->first < v) { // w, e->first, v
		for (int w=0; w<e->first; w++) {
		    amin(dp[k+1][v][w], dp[k][e->first][w] + e->second);
		    amin(dp[k+1][v][w], dp[k][e->first][v] + e->second);
		}
	    }
	    if (v < e->first) { // v, e->first, w
		for (int w=e->first+1; w<=N+1; w++) {
		    amin(dp[k+1][v][w], dp[k][e->first][w] + e->second);
		    amin(dp[k+1][v][w], dp[k][e->first][v] + e->second);
		}
	    }
	}
    }

    int ans = INF;
    REP (i, N+2) REP (j, N+2) amin(ans, dp[K][i][j]);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}