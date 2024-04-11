#include<set>
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

struct Seg {
    Mint a0, a1, b0, b1;
    Seg() {
	a0.undef();
    }
    Seg(Mint p) {
	a0 = 1 - p;
	a1 = p;
	b0 = 1;
	b1 = p;
    }

    Mint eval() {
	assert(a0 != 1);
	return b0 / (1-a0);
    }

    static const Seg UNIT;
};
const Seg Seg::UNIT = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    if (x.a0.isnan()) return y;
    if (y.a0.isnan()) return x;
    Seg z;
    z.a0 = x.a0 + x.a1 * y.a0;
    z.a1 = x.a1 * y.a1;
    z.b0 = x.b0 + x.b1 * y.b0;
    z.b1 = x.b1 * y.b1;
    return z;
};

struct SegTree {
    int n, m;
    vector<Seg> d;

    SegTree() {}

    SegTree(int n_) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::UNIT);
    }

    template<class T> SegTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::UNIT);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
    }

    template<class Iter> SegTree(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::UNIT);
	REP (i, n) d[i+m] = Seg(*(begin+i));
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
    }

    Seg at(int x) const {
	return d[x+m];
    }

    void modify(int x, const Seg &s) {
	x += m;
	d[x] = s;
	for (x>>=1; x; x>>=1) d[x] = d[x*2] * d[x*2+1];
    }

    Seg query(int x, int y) const {
	Seg lval = Seg::UNIT, rval = Seg::UNIT;
	for (x+=m, y+=m; x<y; x>>=1, y>>=1) {
	    if (x&1) { lval = lval * d[x]; x++; }
	    if (y&1) { y--; rval = d[y] * rval; }
	}
	return lval * rval;
    }

    Seg query2(int x, int y) const { return query2(x, y, 1, 0, m); }

    Seg query2(int x, int y, int k, int l, int r) const {
	assert(x < r || l < y); // Has intersection;
	if (x<=l && r<=y) return d[k];
	int mid = (l+r)/2;
	if (y <= mid) return query2(x, y, k*2, l, mid);
	if (mid <= x) return query2(x, y, k*2+1, mid, r);
	return query2(x, y, k*2, l, mid) * query2(x, y, k*2+1, mid, r);
    }
};

int N, Q;

Mint P[200011];
bool act[200011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    Mint inv100 = Mint(1)/100;
    REP (i, N) {
	int p;
	scanf("%d", &p);
	P[i] = p * inv100;
    }
    act[0] = true;
    act[N] = true;
    set<pair<int, int> > se;
    se.emplace(N, 0);

    SegTree X(P, P+N);
    Mint ans = X.query(0, N).eval();

    // [0, N);
    REP ($, Q) {
	int u;
	scanf("%d", &u);
	u--;
	if (act[u]) {
	    // [x, u), [u, y) -> [x, y);
	    auto it = se.lower_bound(make_pair(u, -1));
	    assert(it->first == u);
	    int x = it->second;
	    se.erase(it++);
	    assert(it->second == u);
	    int y = it->first;
	    se.erase(it++);

	    ans -= X.query(x, u).eval();
	    ans -= X.query(u, y).eval();
	    ans += X.query(x, y).eval();
	    se.emplace(y, x);
	    act[u] = false;
	} else {
	    // [x, y) -> [x, u), [u, y)
	    auto it = se.lower_bound(make_pair(u, -1));
	    int x = it->second, y = it->first;
	    se.erase(it);
	    ans -= X.query(x, y).eval();
	    ans += X.query(x, u).eval();
	    ans += X.query(u, y).eval();
	    se.emplace(u, x);
	    se.emplace(y, u);
	    act[u] = true;
	}

	printf("%d\n", ans.geti());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}