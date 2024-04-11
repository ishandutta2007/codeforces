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
int X[200011];
int Y[200011];
int C[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    UnionFind U(N+N);

    REP (i, N-1) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;

	X[i] = x;
	Y[i] = y;
	C[i] = c;

	if (c == -1) {

	} else {
	    int p = __builtin_popcount(c) & 1;
	    if (p == 0) {
		U.link(x, y);
		U.link(x+N, y+N);
	    } else {
		U.link(x, y+N);
		U.link(x+N, y);
	    }
	}
    }

    REP (i, M) {
	int x, y, p;
	scanf("%d%d%d", &x, &y, &p);
	x--; y--;
	if (p == 0) {
	    U.link(x, y);
	    U.link(x+N, y+N);
	} else {
	    U.link(x, y+N);
	    U.link(x+N, y);
	}
    }

    REP (i, N-1) {
	if (C[i] == -1) {
	    if (!U.same(X[i], Y[i]) && !U.same(X[i], Y[i]+N)) {
		U.link(X[i], Y[i]);
		U.link(X[i]+N, Y[i]+N);
	    }
	}
    }

    bool yes = true;
    REP (i, N) if (U.same(i, i+N)) yes = false;

    if (yes) {
	puts("YES");
	REP (i, N-1) {
	    int c;
	    if (C[i] == -1) {
		if (U.same(X[i], Y[i])) {
		    c = 0;
		} else if (U.same(X[i], Y[i]+N)) {
		    c = 1;
		} else {
		    U.link(X[i], Y[i]);
		    U.link(X[i]+N, Y[i]+N);
		    c = 0;
		}
	    } else {
		c = C[i];
	    }
	    printf("%d %d %d\n", X[i]+1, Y[i]+1, c);
	}
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}