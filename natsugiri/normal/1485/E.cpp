#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

const LL INF = 1LL<<60;
int N;
VI G[200011];
LL A[200011];

VI que;
int par[200011];
int dist[200011];
LL high[200011];
LL low[200011];
LL dp[200011];

LL PA[200011];
LL MA[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();

    REP (i, N-1) {
	int v;
	scanf("%d", &v);
	v--;
	G[i+1].push_back(v);
	G[v].push_back(i+1);
    }

    REP (i, N-1) scanf("%lld", A+i+1);

    que.clear();
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    dist[*e] = dist[v] + 1;
	    que.push_back(*e);
	}
    }

    REP (i, N+1) {
	high[i] = -INF;
	low[i] = INF;
	PA[i] = -INF;
	MA[i] = -INF;
    }


    REP (i, N) {
	int v = que[N-1-i];
	dp[v] = 0;
	EACH (e, G[v]) if (*e != par[v]) {
	    amax(dp[v], PA[dist[*e]] - A[*e]);
	    amax(dp[v], MA[dist[*e]] + A[*e]);
	    amax(dp[v], dp[*e] + high[dist[*e]] - A[*e]);
	    amax(dp[v], dp[*e] - low[dist[*e]] + A[*e]);
	}

	amax(PA[dist[v]], dp[v] + A[v]);
	amax(MA[dist[v]], dp[v] - A[v]);
	amax(high[dist[v]], A[v]);
	amin(low[dist[v]], A[v]);

    }


    printf("%lld\n", dp[0]);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}