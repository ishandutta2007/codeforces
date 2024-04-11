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

const int MAXN = 500011;
int N, M, K;
vector<pair<int, char> > G[MAXN];
VI ord;
int par[MAXN];
int depth[MAXN];
int skip[MAXN];
int E[MAXN];

int A[MAXN], B[MAXN], W[MAXN];

const int INF = 1<<30;

void build() {
    memset(par, -1, sizeof par);
    ord.reserve(N);
    ord.push_back(0);

    REP (i, N) {
	E[i] = INF;
	skip[i] = i;
    }
    E[0] = -1;

    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (e->first != par[v]) {
	    int w = e->first;
	    par[w] = v;
	    depth[w] = depth[v] + 1;
	    ord.push_back(w);

	    if (e->second == 'M') {
		E[w] = -1;
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, K) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].emplace_back(y, 'K');
	G[y].emplace_back(x, 'K');
    }

    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;

	A[i] = x;
	B[i] = y;
	W[i] = w;
    }

    UnionFind U(N);
    REP (i, N) EACH (e, G[i]) {
	U.link(i, e->first);
    }
    REP (i, M) {
	if (!U.same(A[i], B[i])) {
	    U.link(A[i], B[i]);
	    G[A[i]].emplace_back(B[i], 'M');
	    G[B[i]].emplace_back(A[i], 'M');
	    W[i] = -1;
	}
    }

    build();

    REP (t, M) {
	int x = A[t], y = B[t], w = W[t];
	if (w == -1) continue;

	int a = x, b = y;
	while (1) {
	    a = skip[a];
	    b = skip[b];
	    if (a == b) break;
	    if (depth[a] < depth[b]) swap(a, b);

	    if (E[a] == INF) E[a] = w;
	    a = par[a];
	}

	int z = a; // lca;
	a = x; b = y;
	while (1) {
	    a = skip[a];
	    b = skip[b];
	    if (a == b) break;
	    if (depth[a] < depth[b]) swap(a, b);
	    skip[a] = z;
	    a = par[a];
	}
    }

    LL ans = 0;
    REP (i, N) {
	if (E[i] == INF) {
	    puts("-1");
	    return;
	}
	if (E[i] != -1) {
	    ans += E[i];
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}