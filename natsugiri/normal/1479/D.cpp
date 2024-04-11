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

#include<random>
#include<chrono>
#include<memory>

uint64_t murmurhash3mixer(uint64_t x) {
    x ^= (x >> 33);
    x *= 0xff51afd7ed558ccdULL;
    x ^= (x >> 33);
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= (x >> 33);
    return x;
}

seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get(),
	murmurhash3mixer(random_device()()),
};

mt19937_64 engine(seq);

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
using namespace TREE_UTILS;
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
	for (; i<n; i|=i+1) d[i] ^= x;
    }
    inline T sum(int r) const {
	T s = T();
	for (; r; r&=r-1) s ^= d[r-1];
	return s;
    }
    T sum(int l, int r) const {
	return sum(r) ^ sum(l);
    }
};

const int SIZE = 1<<19;
const int MAXN = 300011;

VI G[MAXN];
int N, Q;
int A[MAXN];

struct Data {
    int x, y, z, i;
    Data() {}
    Data(int x_, int y_, int z_, int i_): x(x_), y(y_), z(z_), i(i_) {}
};
vector<Data> B[SIZE*2];
int ans[MAXN];
int rnk[MAXN];
VI V[SIZE*2];


void ADD(int left, int right, int x, int y, int z, int i, int l=0, int r=SIZE, int k=1) {
    if (right <= l || r <= left) return;
    if (left <= l && r <= right) {
	B[k].emplace_back(x, y, z, i);
	return;
    }
    ADD(left, right, x, y, z, i, l, (l+r)/2, k*2);
    ADD(left, right, x, y, z, i, (l+r)/2, r, k*2+1);
}

using ULL = unsigned long long;
ULL Z[SIZE*2];
Fenwick<ULL> F(300011);

void DFS(int l=0, int r=SIZE, const int k=1) {
    for (int i=0; i<(int)B[k].size(); ) {
	if (ans[B[k][i].i] != -2) {
	    B[k][i] = B[k].back();
	    B[k].pop_back();
	} else {
	    i++;
	}
    }

    if (!B[k].empty()) {
	for (int i=l; i<r; i++) EACH (e, V[i]) {
	    int v = *e;
	    F.add(rnk[v], Z[i]);
	    F.add(rnk[v] + subsize(v), Z[i]);
	}

	EACH (e, B[k]) {
	    ULL val = 0;
	    val ^= F.sum(rnk[e->x]+1);
	    val ^= F.sum(rnk[e->y]+1);
	    val ^= F.sum(rnk[e->z]+1);
	    if (e->z) {
		val ^= F.sum(rnk[parent(e->z)]+1);
	    }

	    if (val == 0) {
		// not found;
	    } else if (l+1 == r) {
		ans[e->i] = l;
	    } else {
		B[k*2].push_back(*e);
		B[k*2+1].push_back(*e);
	    }
	}
	B[k] = vector<Data>();

	for (int i=l; i<r; i++) EACH (e, V[i]) {
	    int v = *e;
	    F.add(rnk[v], Z[i]);
	    F.add(rnk[v] + subsize(v), Z[i]);
	}
    }

    if (l+1 == r) return;

    DFS(l, (l+r)/2, k*2);
    DFS((l+r)/2, r, k*2+1);
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, SIZE*2) Z[i] = engine();

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    build(G, N);
    REP (i, N) rnk[IMPL::ord[i]] = i;

    REP (i, Q) ans[i] = -2;

    REP (i, Q) {
	int u, v, l, r;
	scanf("%d%d%d%d", &u, &v, &l, &r);
	l--;
	u--;
	v--;
	ADD(l, r, u, v, lca(u, v), i);
    }

    REP (i, N) {
	V[A[i]].push_back(i);
    }

    DFS();

    REP (i, Q) printf("%d\n", ans[i]+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}