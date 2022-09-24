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
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};
template<unsigned MOD_> struct ModInt {
    static const unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
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

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 998244353;
typedef ModInt<MOD> Mint;

int N, K;
char S[1011];
char T[1011];

int a(int i, bool one) {
    int ret = i;
    if (one) ret += N;
    return ret;
}
int b(int i, bool one) {
    int ret = N+N+i;
    if (one) ret += K;
    return ret;
}

bool bad[4011];
bool checked[4011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    reverse(S, S+N);

    Mint ans = 0;

    for (K=1; K<N; K++) {
	UnionFind U(N+N+K+K);
	REP (i, N/2) {
	    U.link(a(i, 0), a(N-1-i, 0));
	    U.link(a(i, 1), a(N-1-i, 1));
	}
	REP (i, K/2) {
	    U.link(b(i, 0), b(K-1-i, 0));
	    U.link(b(i, 1), b(K-1-i, 1));
	}

	REP (i, K) {
	    if (S[i] == '0') {
		U.link(a(i, 0), b(i, 0));
		U.link(a(i, 1), b(i, 1));
	    }
	    if (S[i] == '1') {
		U.link(a(i, 0), b(i, 1));
		U.link(a(i, 1), b(i, 0));
	    }
	}

	memset(bad, 0, sizeof bad);
	bad[U.root(a(0, 0))] = true;
	bad[U.root(b(0, 0))] = true;
	for (int i=K; i<N; i++) {
	    if (S[i] == '0') {
		bad[U.root(a(i, 1))] = true;
	    }
	    if (S[i] == '1') {
		bad[U.root(a(i, 0))] = true;
	    }
	}

	bool yes = true;
	REP (i, N) {
	    if (U.same(a(i, 0), a(i, 1))) {
		yes = false;
		break;
	    }
	    if (bad[U.root(a(i, 0))] && bad[U.root(a(i, 1))]) {
		yes = false;
		break;
	    }
	}
	if (yes) REP (i, K) {
	    if (U.same(b(i, 0), b(i, 1))) {
		yes = false;
		break;
	    }
	    if (bad[U.root(b(i, 0))] && bad[U.root(b(i, 1))]) {
		yes = false;
		break;
	    }
	}

	if (yes) {
	    memset(checked, 0, sizeof checked);
	    Mint tmp = 1;
	    REP (i, N) {
		if (checked[U.root(a(i, 0))]) continue;
		checked[U.root(a(i, 0))] = checked[U.root(a(i, 1))] = true;
		if (!bad[U.root(a(i, 0))] && !bad[U.root(a(i, 1))]) {
		    tmp += tmp;
		}
	    }
	    REP (i, K) {
		if (checked[U.root(b(i, 0))]) continue;
		checked[U.root(b(i, 0))] = checked[U.root(b(i, 1))] = true;
		if (!bad[U.root(b(i, 0))] && !bad[U.root(b(i, 1))]) {
		    tmp += tmp;
		}
	    }

	    ans += tmp;
	}
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}