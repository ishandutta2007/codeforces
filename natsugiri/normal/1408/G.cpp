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
template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

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

struct Seg {
    vector<Mint> dp;
    Seg() {
	dp.resize(1);
	dp[0] = 1;
    }
    Seg(int) {
	dp.resize(2);
	dp[0] = 0;
	dp[1] = 1;
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.dp.assign(x.dp.size() + y.dp.size() - 1u, 0);
    REP (i, x.dp.size()) REP (j, y.dp.size()) {
	z.dp[i+j] += x.dp[i] * y.dp[j];
    }
    return z;
};


int N;
int A[1511][1511];
struct Edge {
    int x, y;
    int c;
    Edge() {}
    Edge(int x_, int y_, int c_): x(x_), y(y_), c(c_) {}

    bool operator<(const Edge &o) const {
	return c < o.c;
    }
};

pair<int, int> R[1511][1511];
int iter[1511];

vector<Edge> E;

Seg seg[1511];
Mint ans[1511];
int Es[1511];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	REP (j, N) {
	    scanf("%d", A[i]+j);
	}
    }

#ifdef LOCAL
    N = 12;
    int len = N * (N-1) / 2;
    VI tmp(len);
    REP (i, len) tmp[i] = i + 1;
    random_shuffle(tmp.begin(), tmp.end());
    int cnt = 0;
    REP (i, N) REP (j, i) {
	A[i][j] = A[j][i] = tmp[cnt++];
    }
    eprintf("%d\n", N);
    REP (i, N) {
	REP (j, N) eprintf("%d ", A[i][j]);
	eprintf("\n");
    }
#endif

    REP (i, N) REP (j, N) {
	R[i][j] = make_pair(A[i][j], j);
    }

    REP (i, N) {
	sort(R[i], R[i]+N);
    }

    REP (i, N) REP (j, i) E.emplace_back(i, j, A[i][j]);

    sort(E.begin(), E.end());
    UnionFind U(N);

    REP (i, N) seg[i] = Seg(0);

    vector<pair<int, int> > stk;

    EACH (e, E) {
	int x = e->x;
	int y = e->y;
	x = U.root(x);
	y = U.root(y);

	if (!U.same(x, y)) {
	    U.link(x, y);
	    if (y == U.root(x)) {
		swap(x, y);
	    }
	    assert(U.root(x) == x);
	    assert(U.root(y) == x);

	    assert(x != y);
	    Seg s = seg[x] + seg[y];
	    seg[x] = s;
	    seg[y] = Seg::IDENTITY;
	    Es[x] += Es[y];
	}
	Es[x]++;
	int sz = U.count_node(x);
	if (Es[x] == sz * (sz-1) / 2) {
	    seg[x].dp[1] += 1;
	}
    }

    Seg total = seg[U.root(0)];
    REP (i, total.dp.size()) if (i <= N) ans[i] += total.dp[i];
    for (int i=1; i<=N; i++) {
	printf("%d%c", ans[i].geti(), " \n"[i==N]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}