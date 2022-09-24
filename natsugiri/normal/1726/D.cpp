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

int N, M;
VI G[200011];
int X[200011];
int Y[200011];
char ans[200011];

VI que;
int par[200011];
int pari[200011];

VI E;
bool triangle() {
    if (E.size() == 3) {
	pair<int, int> P[3];
	REP (i, 3) {
	    int x = X[E[i]];
	    int y = Y[E[i]];
	    if (x > y) swap(x, y);
	    P[i] = make_pair(x, y);
	}
	sort(P, P+3);

	if (P[0].first == P[1].first) {
	    if (P[0].second == P[2].first && P[1].second == P[2].second) return true;
	    if (P[0].second == P[2].second && P[1].second == P[2].first) return true;
	}
    }

    return false;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) G[i].clear();
    E.clear();
    UnionFind U(N);


    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;

	if (U.same(x, y)) {
	    E.push_back(i);
	    ans[i] = '1';
	} else {
	    U.link(x, y);
	    G[x].push_back(i);
	    G[y].push_back(i);
	    ans[i] = '0';
	}
    }

    ans[M] = 0;

    if (triangle()) {
	int s = X[E[0]];
	par[s] = s;
	que.clear();
	que.push_back(s);
	for (int i=0; i<(int)que.size(); i++) {
	    int v = que[i];
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w == par[v]) continue;
		par[w] = v;
		pari[w] = *e;
		que.push_back(w);
	    }
	}

	ans[E[0]] = '0';
	ans[pari[Y[E[0]]]] = '1';
    }

    puts(ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}