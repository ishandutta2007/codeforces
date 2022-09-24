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

int N;
VI G[3011];

LL dp[3011][3011];

int par[3011][3011];
int sz[3011][3011];
int out[3011][3011];
VI cur[3011], nxt[3011];

void MAIN() {
    scanf("%d", &N);
#ifdef MYTEST
    N = 3000;
#endif
    REP (i, N-1) {
	int x, y;

#ifdef MYTEST
	x = i;
	y = i+1;
#else
	scanf("%d%d", &x, &y);
	x--; y--;
#endif

	G[x].push_back(y);
	G[y].push_back(x);
	dp[x][y] = 1;
	dp[y][x] = 1;
    }

    VI ord;
    ord.reserve(N);
    REP (s, N) {
	par[s][s] = s;
	cur[s].push_back(s);

	ord.clear();
	ord.push_back(s);
	REP (i, N) {
	    int v = ord[i];
	    EACH (e, G[v]) if (*e != par[s][v]) {
		par[s][*e] = v;
		ord.push_back(*e);
	    }
	}

	REP (i, N) {
	    int v = ord[N-1-i];
	    sz[s][v] = 1;
	    EACH (e, G[v]) if (*e != par[s][v]) {
		sz[s][v] += sz[s][*e];
	    }
	}

	EACH (e, G[s]) {
	    out[s][*e] = N - sz[s][*e];
	}

	for (int i=1; i<N; i++) {
	    int v = ord[i];
	    EACH (e, G[v]) if (*e != par[s][v]) {
		out[s][*e] = out[s][v];
	    }
	}
    }

    REP (t, N) {
	REP (s, N) {
	    EACH (e, cur[s]) {
		EACH (f, G[*e]) if (*f != par[s][*e]) {
		    par[s][*f] = *e;
		    nxt[s].push_back(*f);

		    amax(dp[s][*f], dp[s][*e] + (LL)sz[s][*e] * out[s][*e]);
		    amax(dp[*f][s], dp[s][*e] + (LL)sz[s][*e] * out[s][*e]);
		}
	    }
	    swap(cur[s], nxt[s]);
	    nxt[s].clear();
	}
    }

    LL ans = 0;
    REP (s, N) REP (v, N) amax(ans, dp[s][v]);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}