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

namespace SCC {
const int MAXN = 1000111; // TODO: check the maximum size;
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

// shrink(false, false) returns directed forest, topological sorted;
Adj shrink(bool self_loop, bool parallel_edges) {
    Adj h(cnt);
    REP (v, n) EACH (e, g[v]) if (self_loop || v != *e) h[scc[v]].push_back(scc[*e]);
    if (!parallel_edges) REP (v, cnt) {
	sort(h[v].begin(), h[v].end());
	h[v].erase(unique(h[v].begin(), h[v].end()), h[v].end());
    }
    return h;
}
}; // namespace SCC;

int N, M;
VI G[1000111];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) G[i].clear();
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	if (x != y) {
	    G[x].push_back(y);
	}
    }

    if (SCC::build(G, N) <= 1) {
	puts("No");
    } else {
	puts("Yes");
	VI jury, cont;
	REP (i, N) {
	    if (SCC::scc[i] == SCC::cnt-1) {
		jury.push_back(i+1);
	    } else {
		cont.push_back(i+1);
	    }
	}
	printf("%d %d\n", (int)jury.size(), (int)cont.size());
	rprintf("%d", jury.begin(), jury.end());
	rprintf("%d", cont.begin(), cont.end());
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}