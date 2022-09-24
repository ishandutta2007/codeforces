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
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

const int MAXV = 100051;
int N, M;

struct Edge {
    int x, y;
    int d;
} E[MAXV];
vector<Edge> S;
vector<pair<int, int> > G[MAXV];

const int LOGV = 18;
int depth[MAXV];
int parent[LOGV][MAXV];
LL dist[MAXV];

void build_lca(/* VI G[], int N, */ const int root=0) {
    depth[root] = 0;
    dist[root] = 0;
    parent[0][root] = root;
    VI ord; ord.reserve(N);
    ord.push_back(root);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (e->first != parent[0][v]) {
	    ord.push_back(e->first);
	    depth[e->first] = depth[v] + 1;
	    dist[e->first] = dist[v] + e->second;
	    parent[0][e->first] = v;
	}
    }
    REP (t, LOGV-1) REP (v, N) parent[t+1][v] = parent[t][parent[t][v]];
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    REP (t, LOGV) if ((depth[x] - depth[y]) & (1 << t)) x = parent[t][x];
    if (x == y) return x;
    for (int t=LOGV; t--;) {
	if (parent[t][x] != parent[t][y]) {
	    x = parent[t][x];
	    y = parent[t][y];
	}
    }
    return parent[0][x];
}

LL distance(int x, int y, int z=-1) {
    if (z == -1) z = lca(x, y);
    return dist[x] + dist[y] - 2 * dist[z];
}

void build_tree() {
    UnionFind U(N);
    REP (i, M) {
	if (U.same(E[i].x, E[i].y)) {
	    S.push_back(E[i]);
	} else {
	    U.link(E[i].x, E[i].y);
	    G[E[i].x].emplace_back(E[i].y, E[i].d);
	    G[E[i].y].emplace_back(E[i].x, E[i].d);
	}
    }
}

LL DD[64][64];
int CName[MAXV];
LL Cdist[64][MAXV];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, d;
	scanf("%d%d%d", &x, &y, &d);
	x--; y--;
	E[i].x = x;
	E[i].y = y;
	E[i].d = d;
    }

    build_tree();
    build_lca();

    VI C;
    EACH (e, S) {
	C.push_back(e->x);
	C.push_back(e->y);
    }
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    REP (i, C.size()) CName[C[i]] = i;

    memset(DD, 0x3f, sizeof DD);
    EACH (e, S) {
	amin(DD[CName[e->x]][CName[e->y]], (LL)(e->d));
	amin(DD[CName[e->y]][CName[e->x]], (LL)(e->d));
    }
    REP (i, C.size()) REP (j, C.size()) {
	amin(DD[i][j], distance(C[i], C[j]));
    }
    REP (k, C.size()) REP (i, C.size()) REP (j, C.size())
	amin(DD[i][j], DD[i][k] + DD[k][j]);

    memset(Cdist, 0x3f, sizeof Cdist);
    REP (i, C.size()) {
	REP (v, N) {
	    Cdist[i][v] = distance(C[i], v);
	}
    }
    REP (i, C.size()) {
	REP (v, N) {
	    REP (j, C.size()) {
		amin(Cdist[i][v], DD[i][j] + Cdist[j][v]);
	    }
	}
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;

	LL ans = distance(x, y);
	REP (i, C.size()) {
	    amin(ans, Cdist[i][x] + Cdist[i][y]);
	}
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}