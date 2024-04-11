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
struct Edge {
    int x, y, c;
    bool operator<(const Edge &o) const {
	return c < o.c;
    }
} E[200011];

int N, M, K;

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	int x, y, s;
	scanf("%d%d%d", &x, &y, &s);
	x--; y--;
	E[i].x = x;
	E[i].y = y;
	E[i].c = s;
    }

    sort(E, E+M);

    UnionFind U(N);
    REP (i, M) if (E[i].c <= K) {
	U.link(E[i].x, E[i].y);
    }


    LL ans = 1LL<<60;

    if (U.count_tree() == 1) {
	REP (i, M) if (E[i].c <= K) {
	    amin(ans, (LL)K - E[i].c);
	}

	U = UnionFind(N);
	REP (i, M) if (E[i].c >= K) {
	    U.link(E[i].x, E[i].y);
	    amin(ans, (LL)E[i].c - K);
	    break;
	}

    } else {
	U = UnionFind(N);
	LL tmp = 0;
	REP (i, M) if (!U.same(E[i].x, E[i].y)) {
	    U.link(E[i].x, E[i].y);
	    if (E[i].c >= K) {
		tmp += E[i].c - K;
	    }
	}

	amin(ans, tmp);
    }


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}