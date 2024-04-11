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


const int MAX_V = 100011;
const int LOG_V = 18;
int N, M;
VI G[MAX_V];

struct Edge {
    int x, y, i;
    bool operator<(const Edge &r) const {
	return x != r.x?
	    x < r.x:
	    y < r.y;
    }
};
vector<Edge> E;

int sums[MAX_V];

int depth[MAX_V];
int parent[LOG_V][MAX_V];
int dp[LOG_V][MAX_V];
VI ord;

void build_lca() {
    memset(depth, -1, sizeof depth);
    ord.reserve(N);

    REP (root, N) if (depth[root] == -1) {
	depth[root] = 0;
	parent[0][root] = root;

	int idx = ord.size();
	ord.push_back(root);

	for (; idx<(int)ord.size(); idx++) {
	    int v = ord[idx];
	    EACH (e, G[v]) if (*e != parent[0][v]) {
		ord.push_back(*e);
		depth[*e] = depth[v] + 1;
		parent[0][*e] = v;
		G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	    }
	}
    }
    REP (t, LOG_V-1) REP (v, N) parent[t+1][v] = parent[t][parent[t][v]];
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    REP (t, LOG_V) if ((depth[x] - depth[y]) & (1 << t)) x = parent[t][x];
    if (x == y) return x;
    for (int t=LOG_V; t--;) {
	if (parent[t][x] != parent[t][y]) {
	    x = parent[t][x];
	    y = parent[t][y];
	}
    }
    return parent[0][x];
}

VI ans;
void add_ans(int x, int y) {
    Edge key;
    key.x = min(x, y);
    key.y = max(x, y);
    key.i = -1;

    int k = lower_bound(E.begin(), E.end(), key) - E.begin();
    ans.push_back(E[k].i+1);
}

int get_max(int x, int y) {
    int ret = 0;
    if (depth[x] < depth[y]) swap(x, y);
    REP (t, LOG_V) if ((depth[x] - depth[y]) & (1 << t)) {
	amax(ret, dp[t][x]);
	x = parent[t][x];
    }
    if (x == y) return ret;
    for (int t=LOG_V; t--;) {
	if (parent[t][x] != parent[t][y]) {
	    amax(ret, dp[t][x]);
	    amax(ret, dp[t][y]);
	    x = parent[t][x];
	    y = parent[t][y];
	}
    }
    amax(ret, dp[0][x]);
    amax(ret, dp[0][y]);
    return ret;

}

void MAIN() {
    scanf("%d%d", &N, &M);
    E.reserve(M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	Edge e;
	e.x = min(x, y);
	e.y = max(x, y);
	e.i = i;
	E.push_back(e);
    }
    sort(E.begin(), E.end());

    UnionFind U(N);
    vector<Edge> ad;
    EACH (e, E) {
	int x = e->x;
	int y = e->y;
	if (U.same(x, y)) {
	    ad.push_back(*e);
	} else {
	    U.link(x, y);
	    G[x].push_back(y);
	    G[y].push_back(x);
	}
    }

    build_lca();
    EACH (e, ad) {
	int x = e->x;
	int y = e->y;
	int z = lca(x, y);
//	eprintf("%d %d : %d\n", x+1, y+1, z+1);
	sums[x]++;
	sums[y]++;
	sums[z] -= 2;
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	if (depth[v]) sums[parent[0][v]] += sums[v];
    }
    REP (v, N) dp[0][v] = sums[v];
    REP (t, LOG_V-1) REP (v, N) dp[t+1][v] = max(dp[t][v], dp[t][parent[t][v]]);

    EACH (e, ad) {
	int x = e->x;
	int y = e->y;
	int ma = get_max(x, y);
	if (ma == 1) {
	    add_ans(x, y);
	    while (x != y) {
		if (depth[x] > depth[y]) swap(x, y);
		add_ans(y, parent[0][y]);
		y = parent[0][y];
	    }
	}
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}