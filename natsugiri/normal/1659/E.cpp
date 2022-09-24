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

int N;
int M;

struct Graph{
    UnionFind U, U2;
    VI ev;

    void init() {
	U = UnionFind(N);
	U2 = UnionFind(N);
	ev.assign(N, 0);
    }

    void add(int x, int y, int w) {
	U.link(x, y);

	if (w % 2 == 1) {
	    U2.link(x, y);
	}
    }

    void build() {
	REP (i, N) if (ev[i]) ev[U2.root(i)] = true;
    }

    bool even(int x) {
	return ev[U2.root(x)];
    }
} Z[30];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (t, 30) Z[t].init();

    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;

	REP (t, 30) if (w>>t&1) Z[t].add(x, y, w);

	if (w % 2 == 0) {
	    REP (t, 30) {
		Z[t].ev[x] = Z[t].ev[y] = true;
	    }
	}
    }

    REP (t, 30) Z[t].build();

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;

	bool zero = false;
	REP (t, 30) if (Z[t].U.same(x, y)) {
	    zero = true;
	    break;
	}
	if (zero) {
	    puts("0");
	} else {
	    bool one = false;
	    for (int t=1; t<30; t++) if (Z[t].even(x)) {
		one = true;
		break;
	    }
	    if (one) {
		puts("1");
	    } else {
		puts("2");
	    }
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}