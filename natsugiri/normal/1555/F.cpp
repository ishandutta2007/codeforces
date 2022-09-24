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
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

namespace TREE_UTILS {
#ifdef COMMENT
// Builder;
void build(VI G[], int N, int root=0);
// Tree query;
int meet(int x, int y, int z);
int dist(int x, int y);
int cut_size(int x, int y);
int jump(int x, int y, int k);
int step(int x, int y);

// Rooted-Tree query;
int set_root(int root);
int reroot_depth(int root,  int x);
int reroot_lca(int root, int x, int y);
int reroot_ancestor(int root, int x, int k);
int reroot_la(int root, int x, int d);
int reroot_subsize(int x);
bool reroot_is_ancestor(int root, int x, int y);

int depth(int x);
int lca(int x, int y);
int parent(int x);
int ancestor(int x, int k);
int la(int x, int d);
int subsize(int x);

bool is_ancestor(int x, int y);
// Test x is ancestor of y;
// Return True if x == y;
#endif

namespace IMPL {

const int MAXN = 300011;
const int MAXLOGN = 20; // == __lg(MAXN) + 2;

int n, logn;
VI ord; // pre-order;
int parent[MAXN];
int depth[MAXN];
int ett_in[MAXN], ett_out[MAXN];
int height[MAXN];
int subsize[MAXN];
int rnk[MAXN];

int ett[MAXN * 2], ett_i;
int jump_table[MAXLOGN][MAXN];
int sparse_table[MAXLOGN][MAXN * 2];
int ladder[MAXN * 2];
int ladder_rank[MAXN];

int min_by_depth(int x, int y) {
    return depth[x] < depth[y]? x: y;
}

int max_by_depth(int x, int y) {
    return depth[x] < depth[y]? y: x;
}

void build(VI G[], int N) {

    static_assert(MAXLOGN == __lg(MAXN) + 2);
    const int root = 0;
    n = N;
    logn = __lg(N) + 1; // fill table[0][] .. table[logn][];

    // build Euler-tour;
    vector<pair<int, int> > stk;
    stk.reserve(N);
    stk.emplace_back(root, 0);
    parent[root] = -1;
    ett_i = 0;
    ett_in[root] = 0;
    ord.clear();
    ord.push_back(root);

    while (!stk.empty()) {
	int v = stk.back().first;
	int i = stk.back().second;
	ett[ett_i++] = v;
	if (i == (int)G[v].size()) {
	    ett_out[v] = ett_i-1;
	    stk.pop_back();
	} else {
	    int w = G[v][i];
	    stk.back().second++;
	    if (w == parent[v]) {
		ett_i--;
	    } else {
		parent[w] = v;
		ett_in[w] = ett_i;
		ord.push_back(w);
		stk.emplace_back(w, 0);
	    }
	}
    }

    // build depth, subsize, height;
    depth[root] = 0;
    for (int i=1; i<N; i++) {
	int v = ord[i];
	depth[v] = depth[parent[v]] + 1;
    }
    for (int i=N; i--;) {
	int v = ord[i];
	subsize[v] = 1;
	height[v] = 0;
	EACH (e, G[v]) if (*e != parent[v]) {
	    subsize[v] += subsize[*e];
	    amax(height[v], height[*e] + 1);
	}
    }

    REP (i, N) rnk[ord[i]] = i;

    // build jump table;
    REP (v, N) jump_table[0][v] = parent[v];
    REP (t, logn) REP (v, N) {
	int p = jump_table[t][v];
	jump_table[t+1][v] = (p == -1? -1: jump_table[t][p]);
    }

    // build sparse table;
    REP (t, logn+1) memset(sparse_table[t], 0, sizeof (int) * (ett_i + 1));
    REP (i, ett_i+1) sparse_table[0][i] = ett[i];
    REP (t, logn) REP (i, ett_i+1) {
	int j = i + (1<<t);
	if (j > ett_i) break;
	int x = sparse_table[t][i];
	int y = sparse_table[t][j];
	sparse_table[t+1][i] = min_by_depth(x, y);
    }

    // build ladder;
    stk.emplace_back(root, 0);
    int ladder_i = 0;
    VI snake;
    while (!stk.empty()) {
	int s = stk.back().first;
	stk.pop_back();
	snake.clear();
	snake.push_back(s);
	while (1) {
	    int v = snake.back();
	    int w = -1;
	    EACH (e, G[v]) if (*e != parent[v] && height[*e] + 1 == height[v]) {
		w = *e;
		break;
	    }
	    if (w == -1) break;
	    snake.push_back(w);
	    EACH (e, G[v]) if (*e != parent[v] && *e != w) {
		stk.emplace_back(*e, 0);
	    }
	}
	int len = snake.size();
	reverse(snake.begin(), snake.end());
	REP (i, len) {
	    if (snake.back() == root) break;
	    snake.push_back(parent[snake.back()]);
	}
	for (int i=snake.size(); i--;) {
	    if (i < len) ladder_rank[snake[i]] = ladder_i;
	    ladder[ladder_i++] = snake[i];
	}
    }
}

// Lowest Common Ancestor;
int lca(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    int left = ett_in[x], right = ett_in[y];
    if (left > right) swap(left, right);
    int range = right - left + 1;
    int lg = __lg(range);
    assert(lg <= logn);
    int guess0 = sparse_table[lg][left];
    int guess1 = sparse_table[lg][right - (1<<lg) + 1];
    return min_by_depth(guess0, guess1);
}

// kth-ancestor
int ancestor(int x, int k) {
    assert(0 <= x && x < n);
    if (k < 0 || depth[x] < k) return -1;
    if (k == 0) return x;
    int lg = __lg(k);
    assert(lg < MAXLOGN);
    int y = jump_table[lg][x];
    k -= 1<<lg;
    return ladder[ladder_rank[y] - k];
}

// return vk;
// path xy = [v0, v1, ..., vd];
int jump(int x, int y, int k) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    int z = lca(x, y);
    if (k <= depth[x] - depth[z]) {
	return ancestor(x, k);
    } else {
	int d = depth[x] + depth[y] - 2 * depth[z];
	if (k <= d) return ancestor(y, d - k);
	else return -1;
    }
}

// Level-Ancestor;
int la(int x, int d) {
    assert(0 <= x && x < n);
    if (d < 0 || depth[x] < d) return -1;
    return ancestor(x, depth[x] - d);
}

int dist(int x, int y, int z=-1) { 
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    if (z == -1) z = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[z];
}

int cut_size(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    if (parent[x] == y) {
	return subsize[x];
    } else if (parent[y] == x) {
	return n - subsize[y];
    } else {
	return -1;
    }
}

bool is_ancestor(int x, int y) {
    return ett_in[y] <= ett_in[x] && ett_in[x] <= ett_out[y];
}
}; // namespace IMPL;


int reroot;

void build(VI G[], int N, int root=0) {
    reroot = root;
    IMPL::build(G, N);
}

int meet(int x, int y, int z) {
    return IMPL::max_by_depth(IMPL::lca(x, y),
	    IMPL::max_by_depth(IMPL::lca(y, z), IMPL::lca(z, x)));
}

int jump(int x, int y, int k) {
    return IMPL::jump(x, y, k);
}

int step(int x, int y) {
    return jump(x, y, 1);
}

int dist(int x, int y) {
    return IMPL::dist(x, y);
}

int cut_size(int x, int y) {
    return IMPL::cut_size(x, y);
}

void set_root(int root) {
    reroot = root;
}

int reroot_depth(int root, int x) {
    if (root == 0) {
	return IMPL::depth[x];
    } else {
	return IMPL::dist(root, x);
    }
}

int reroot_lca(int root, int x, int y) {
    if (root == 0) {
	return IMPL::lca(x, y);
    } else {
	return meet(root, x, y);
    }
}

int reroot_ancestor(int root, int x, int k) {
    return IMPL::jump(x, root, k);
}

int reroot_la(int root, int x, int d) {
    if (root == 0) {
	return IMPL::la(x, d);
    } else {
	return reroot_ancestor(root, x, IMPL::dist(x, root) - d);
    }
}

int reroot_subsize(int root, int x) {
    if (root == 0) {
	return IMPL::subsize[x];
    } else if (root == x) {
	return IMPL::n;
    } else {
	int y = step(x, root);
	return IMPL::cut_size(x, y);
    }
}

bool reroot_is_ancestor(int root, int x, int y) { // test y -> x -> root is path;
    if (root == 0) {
	return IMPL::is_ancestor(x, y);
    } else {
	return IMPL::dist(y, x) + IMPL::dist(x, root) == IMPL::dist(y, root);
    }
}

int depth(int x) {
    return reroot_depth(reroot, x);
}

int lca(int x, int y) {
    return reroot_lca(reroot, x, y);
}

int ancestor(int x, int k) {
    return reroot_ancestor(reroot, x, k);
}

int parent(int x) {
    return ancestor(x, 1);
}

int la(int x, int d) {
    return reroot_la(reroot, x, d);
}

int subsize(int x) {
    return reroot_subsize(reroot, x);
}

bool is_ancestor(int x, int y) {
    return reroot_is_ancestor(reroot, x, y);
}
}; // namespace TREE_UTILS;

template<class T> struct Fenwick {
    int n;
    T* d;
    Fenwick() : n(0), d(NULL) {}
    Fenwick(int n_) : n(n_) {
	d = new T[n_]();
    }
    Fenwick(const Fenwick &y) : n(y.n) {
	d = new T[n];
	memcpy(d, y.d, sizeof (T) * n);
    }
    ~Fenwick() {
	delete[] d; d = NULL;
	n = 0;
    }
    friend void swap(Fenwick &x, Fenwick &y) {
	swap(x.n, y.n); swap(x.d, y.d);
    }
    Fenwick& operator=(Fenwick y) {
	swap(*this, y);
	return *this;
    }
    inline void add(int i, const T &x) {
	for (; i<n; i|=i+1) d[i] += x;
    }
    inline T sum(int r) const {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) const {
	return sum(r) - sum(l);
    }
};

int N, Q;

int X[500011];
int Y[500011];
int W[500011];
bool link[500011];

VI G[300011];
int D[300011];
int par[300011];

void MAIN() {
    scanf("%d%d", &N, &Q);

#ifdef LOCAL
    N = 300000;
    Q = 500000;
    REP (i, Q) {
	X[i] = rand() % N + 1;
	Y[i] = rand() % N + 1;
	W[i] = rand() % 2;
    }
#else
    REP (i, Q) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	X[i] = x;
	Y[i] = y;
	W[i] = w;
    }
#endif

    UnionFind U(N+1);

    REP (i, Q) {
	int x = X[i];
	int y = Y[i];
	// int w = W[i];

	if (!U.same(x, y)) {
	    G[x].push_back(i);
	    G[y].push_back(i);
	    U.link(x, y);
	}
    }

    memset(D, -1, sizeof D);

    D[0] = 0;
    VI que;
    for (int i=1; i<=N; i++) {
	if (!U.same(0, i)) {
	    U.link(0, i);
	    que.clear();
	    que.push_back(i);
	    D[i] = 0;
	    for (int j=0; j<(int)que.size(); j++) {
		int v = que[j];
		EACH (e, G[v]) {
		    int w = X[*e] ^ Y[*e] ^ v;
		    if (D[w] == -1) {
			D[w] = D[v] ^ W[*e];
			par[w] = v;
			que.push_back(w);
		    }
		}
	    }
	}
    }


    REP (i, N+1) G[i].clear();

    /////////////////////////////////////////////////////
    U = UnionFind(N+1);

    REP (i, Q) {
	int x = X[i];
	int y = Y[i];
	// int w = W[i];

	if (!U.same(x, y)) {
	    G[x].push_back(y);
	    G[y].push_back(x);
	    U.link(x, y);
	    link[i] = true;
	}
    }

    for (int i=1; i<=N; i++) {
	if (!U.same(0, i)) {
	    G[0].push_back(i);
	    G[i].push_back(0);
	    U.link(0, i);
	}
    }

    TREE_UTILS::build(G, N+1);


    Fenwick<int> cycle(N+11);

    REP (i, Q) {
	bool yes;
	if (link[i]) {
	    yes = true;
	} else {
	    int x = X[i];
	    int y = Y[i];
	    int w = W[i];
	    
	    using namespace TREE_UTILS;
	    int z = TREE_UTILS::lca(x, y);
	    int c = cycle.sum(IMPL::rnk[x]+1) + cycle.sum(IMPL::rnk[y]+1) - 2 * cycle.sum(IMPL::rnk[z]+1);
	    if (c) {
		yes = false;
	    } else {
		int d = w + D[x] + D[y] - 2*D[z] + 100;
		if (d % 2 == 1) {
		    yes = true;
		    while (x != z) {
			cycle.add(IMPL::rnk[x], 1);
			cycle.add(IMPL::rnk[x]+subsize(x), -1);
			x = par[x];
		    }
		    while (y != z) {
			cycle.add(IMPL::rnk[y], 1);
			cycle.add(IMPL::rnk[y]+subsize(y), -1);
			y = par[y];
		    }
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