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
int N, M;
int CostA[100011];
int CostB[100011];

struct Edge {
    int x, y;
    LL c;
    Edge() {}
    Edge(int x_, int y_, LL c_): x(x_), y(y_), c(c_) {}

    bool operator<(const Edge &o) const {
	return c < o.c;
    }
};

vector<Edge> E;

void MAIN() {
    scanf("%d%d", &M, &N);
    REP (i, M) scanf("%d", CostA+i);
    REP (i, N) scanf("%d", CostB+i);

    REP (i, M) {
	int len;
	scanf("%d", &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    LL c = (LL)CostA[i] + CostB[x];

	    E.emplace_back(i, x + M, c);
	}
    }

    sort(E.begin(), E.end());
    reverse(E.begin(), E.end());
    UnionFind U(N+M);
    LL ans = 0;
    EACH (e, E) {
	if (!U.same(e->x, e->y)) {
	    U.link(e->x, e->y);
	} else {
	    ans += e->c;
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