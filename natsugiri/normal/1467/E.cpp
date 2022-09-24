#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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

const int MAXN = 200011;
const int MAXLOGN = 19; // == __lg(MAXN) + 2;

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

int N;
VI G[200011];

int A[200011];
VI X;
pair<int, int> AI[200011];
bool bad[200011];
LL dp[200011];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);


    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    using namespace TREE_UTILS;
    build(G, N);


    REP (i, N) AI[i] = make_pair(A[i], i);
    sort(AI, AI+N);

    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && AI[i].first == AI[j].first) j++;

	if (j-i >= 2) {
	    X.clear();
	    for (int k=i; k<j; k++) X.push_back(AI[k].second);
	    sort(X.begin(), X.end(), [&](int x, int y) {
		    return IMPL::ett_in[x] < IMPL::ett_in[y];
		    });

	    REP (k, X.size()) {
		int x = X[k];
		int y = X[(k+1) % X.size()];
		int z = lca(x, y);
		bad[x] = true;

		if (z == x) {
		    dp[0]++;
		    dp[step(x, y)]--;
		    dp[y]++;
		} else if (z == y) {
		    dp[0]++;
		    dp[step(y, x)]--;
		    dp[x]++;
		} else {
		    dp[x]++;
		    dp[y]++;
		}
	    }
	}

	i = j;
    }

    // rprintf("%d", IMPL::ord.begin(), IMPL::ord.end());

    EACH (e, IMPL::ord) {
	int v = *e;
	EACH (f, G[v]) if (*f != parent(v)) {
	    dp[*f] += dp[v];
	}
    }

    int ans = 0;
    REP (i, N) if (!bad[i] && dp[i] == 0) ans++;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}