#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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


namespace SCC {
const int MAXN = 200011; // TODO: check the maximum size;
typedef vector<VI> Adj;
const VI *g;
int n;
int scc[MAXN]; // scc[v] := v's index of shrinked graph; topological order;
int cnt; // size of shrinked graph;
int num[MAXN]; // num[v] := dfs position of v;
int low[MAXN];
int par[MAXN];
int iter[MAXN];
int st[MAXN], st_i;
int vis[MAXN], vis_i;
bool in_vis[MAXN];

int build(const VI *g_, int n_) { // HINT: Adj G(N); build(&G[0], N);
    g = g_;
    n = n_;
    memset(scc, -1, sizeof (int) * n);
    cnt = 0;
    memset(num, -1, sizeof (int) * n);
    memset(low, -1, sizeof (int) * n);
    memset(par, -1, sizeof (int) * n);
    memset(iter, 0, sizeof (int) * n);
    st_i = 0;
    vis_i = 0;
    memset(in_vis, 0, sizeof (bool) * n);

    int time = 0;

    REP (s, n) if (scc[s] == -1) {
	st[st_i++] = s;
	while (st_i) {
	    int v = st[st_i-1];
	    if (num[v] == -1) {
		low[v] = num[v] = time++;
		vis[vis_i++] = v; in_vis[v] = true;
	    }

	    if (iter[v]) {
		int w = g[v][iter[v]-1];
		if (v == par[w]) amin(low[v], low[w]);
		else if (in_vis[w]) amin(low[v], num[w]);
	    }

	    if (iter[v] < (int)g[v].size()) {
		int w = g[v][iter[v]++];
		if (num[w] == -1) {
		    par[w] = v;
		    st[st_i++] = w;
		}
	    } else {
		st_i--;
		if (low[v] == num[v]) {
		    while (1) {
			int w = vis[--vis_i]; in_vis[w] = false;
			scc[w] = cnt;
			if (v == w) break;
		    }
		    cnt++;
		}
	    }
	}
    }
    REP (v, n) scc[v] = cnt - 1 - scc[v];
    return cnt;
}
}; // namespace SCC;

int N;
int M;

int X[200011];
int Y[200011];
int L[200011];

VI G[200011];

vector<pair<int, int> > H[200011];
LL D[200011];

LL GCD[200011];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int x, y, l;
	scanf("%d%d%d", &x, &y, &l);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	L[i] = l;
	G[x].push_back(y);
    }

    SCC::build(G, N);

    REP (i, M) {
	int x = X[i];
	int y = Y[i];
	int l = L[i];

	if (SCC::scc[x] == SCC::scc[y]) {
	    H[x].emplace_back(y, l);
	}
    }

    memset(D, 0x3f, sizeof D);
    priority_queue<pair<LL, int> > Q;
    REP (i, N) if (D[i] == D[N]) {
	D[i] = 0;
	Q.emplace(D[i], i);

	while (!Q.empty()) {
	    LL cst = -Q.top().first;
	    int v = Q.top().second;
	    Q.pop();
	    if (D[v] != cst) continue;

	    EACH (e, H[v]) {
		if (D[e->first] > cst + e->second) {
		    D[e->first] = cst + e->second;
		    Q.emplace(-D[e->first], e->first);
		}
	    }
	}
    }

    REP (i, M) {
	int x = X[i];
	int y = Y[i];
	int l = L[i];

	if (SCC::scc[x] == SCC::scc[y]) {
	    LL tmp = D[x] + l - D[y];
	    assert(tmp >= 0);

	    if (tmp) {
		GCD[SCC::scc[x]] = __gcd(GCD[SCC::scc[x]], tmp);
	    }
	}
    }


    int test;
    scanf("%d", &test);
    REP ($, test) {
	int v;
	LL s, t;
	scanf("%d%lld%lld", &v, &s, &t);
	v--;

	bool yes = false;
	if (s == 0) {
	    yes = true;
	} else {
	    LL g = GCD[SCC::scc[v]];
	    if (g == 0) {
		yes = false;
	    } else {
		LL r = t - s;
		LL x = __gcd(g, t);
		if (r % x == 0) {
		    yes = true;
		} else {
		    yes = false;
		}
	    }
	}

	puts(yes? "YES": "NO");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}