#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
VI offline_lca(VI G[], int N, vector<pair<int, int> > &qs, int root=0) {
    vector<VI> B(N);
    REP (i, qs.size()) {
	B[qs[i].first].push_back(i);
	B[qs[i].second].push_back(i);
    }
    UnionFind U(N);
    VI stk, par, iter(N, 0), ancestor(N, -1), ret(qs.size());
    ancestor[root] = root;
    stk.push_back(root);
    par.push_back(-1);
    while (!stk.empty()) {
	int v = stk.back(), p = par.back();
	if (iter[v] == (int)G[v].size()) {
	    iter[v] = -1;
	    EACH (e, B[v]) {
		int w = v ^ qs[*e].first ^ qs[*e].second;
		if (iter[w] == -1) ret[*e] = ancestor[U.root(w)];
	    }
	    if (p != -1) {
		U.link(v, p);
		ancestor[U.root(p)] = p;
	    }
	    stk.pop_back();
	    par.pop_back();
	} else {
	    int w = G[v][iter[v]++];
	    if (w != p) {
		ancestor[w] = w;
		stk.push_back(w);
		par.push_back(v);
	    }
	}
    }
    return ret;
}

int N;
int M;
int K;
int A[200011], B[200011];

VI G[100011];
int par[100011];
int depth[100011];
int deg[100011];

bool ban[100011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
    }

    UnionFind U(N);
    vector<pair<int, int> > edge;
    REP (i, M) {
	if (!U.same(A[i], B[i])) {
	    U.link(A[i], B[i]);
	    G[A[i]].push_back(B[i]);
	    G[B[i]].push_back(A[i]);
	} else {
	    edge.emplace_back(A[i], B[i]);
	}
    }

    if (M == N-1) {
	REP (i, N) deg[i] = G[i].size();
	VI stk;
	REP (i, N) if (deg[i] <= 1) stk.push_back(i);
	VI ans;
	while ((int)ans.size() < (K+1)/2) {
	    int v = stk.back();
	    stk.pop_back();
	    EACH (e, G[v]) {
		deg[*e]--;
		if (deg[*e] == 1) {
		    stk.push_back(*e);
		}
	    }
	    if (ban[v]) continue;
	    else {
		ans.push_back(v+1);
		EACH (e, G[v]) {
		    ban[*e] = true;
		}
	    }
	}

	puts("1");
	rprintf("%d", ans.begin(), ans.end());
    } else {
	VI ord;
	ord.reserve(N);
	ord.push_back(0);
	REP (i, N) {
	    int v = ord[i];
	    EACH (e, G[v]) if (*e != par[v]) {
		par[*e] = v;
		depth[*e] = depth[v] + 1;
		ord.push_back(*e);
	    }
	}

	auto L = offline_lca(G, N, edge, 0);
	int best_len = 1<<29;
	int best_x = 1, best_y = -1, best_z = -1;
	REP (i, edge.size()) {
	    int x = edge[i].first;
	    int y = edge[i].second;
	    int z = L[i];
	    int len = depth[x] + depth[y] - depth[z] * 2;
	    if (best_len > len) {
		best_len = len;
		best_x = x;
		best_y = y;
		best_z = z;
	    }
	}

	VI ans;
	int y = best_y;
	while (y != best_z) {
	    ans.push_back(y);
	    y = par[y];
	}
	ans.push_back(best_z);
	reverse(ans.begin(), ans.end());
	int x = best_x;
	while (x != best_z) {
	    ans.push_back(x);
	    x = par[x];
	}

	EACH (e, ans) ++*e;

	if (best_len + 1 <= K) {
	    puts("2");
	    printf("%d\n", (int)ans.size());
	    rprintf("%d", ans.begin(), ans.end());
	} else {
	    puts("1");
	    VI ind;
	    REP (i, (K+1)/2) ind.push_back(ans[i*2]);
	    rprintf("%d", ind.begin(), ind.end());
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}