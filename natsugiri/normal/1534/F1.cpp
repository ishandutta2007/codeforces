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
namespace SCC {
const int MAXN = 400111; // TODO: check the maximum size;
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

int N, M;
char buf[400011];
string F[400011];

int A[400011];

VI idx[400011];

int up[400011];
int deg[400011];

VI G[400011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	F[i] = buf;
    }

    REP (i, M) scanf("%d", A+i);

    REP (i, N) idx[i].resize(M, -1);
    int cnt = 0;
    REP (i, N) REP (j, M) if (F[i][j] == '#') {
	idx[i][j] = cnt++;
    }

    memset(up, -1, sizeof up);
    REP (i, N) {
	REP (j, M) if (F[i][j] == '#') {
	    int v = idx[i][j];
	    if (j && up[j-1] != -1) {
		G[up[j-1]].push_back(v);
	    }
	    if (up[j] != -1) {
		G[up[j]].push_back(v);
	    }
	    if (j+1 < M && up[j+1] != -1) {
		G[up[j+1]].push_back(v);
	    }

	    if (i && F[i-1][j] == '#') {
		G[v].push_back(idx[i-1][j]);
	    }
	    if (j && F[i][j-1] == '#') {
		G[v].push_back(idx[i][j-1]);
		G[idx[i][j-1]].push_back(v);
	    }
	}

	REP (j, M) if (F[i][j] == '#') up[j] = idx[i][j];
    }

    int ans = 0;

    if (cnt == 0) {
	ans = 0;
    } else {
	SCC::build(G, cnt);
	REP (v, cnt) {
	    int from = SCC::scc[v];
	    EACH (e, G[v]) {
		int to = SCC::scc[*e];
		if (from != to) {
		    deg[to]++;
		}
	    }
	}

	REP (i, SCC::cnt) {
	    if (deg[i] == 0) ans++;
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}