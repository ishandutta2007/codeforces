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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

struct Seg {
    int len;
    Mint val;
    Seg() : len(0) {}
    Seg(int len_): len(len_) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    Seg z;
    z.len = x.len + y.len;
    z.val = x.val + y.val;
    return z;
};

const LL INVALID = 1LL<<60;
struct Lazy {
    bool zero;
    Mint add;
    Lazy() : zero(false), add(0) {}
    Lazy(bool zero_, Mint add_) : zero(zero_), add(add_) {}

    Lazy& operator*=(const Lazy &y) {
	if (y.zero) {
	    zero = true;
	    add = y.add;
	} else {
	    add += y.add;
	}
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    if (x.len == 0) return x;
    Seg z = x;
    if (y.zero) {
	z.val = 0;
    }
    z.val += z.len * y.add;
    return z;
}

struct SegTreeLazy {
    int m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n=1) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    inline Seg eval(int k) {
	return d[k] * lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s * lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::IDENTITY;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) + eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::IDENTITY;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) + rs;
	    if (x & 1) ls = ls + eval(x++);
	}
	return ls + rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] *= v;
	    if (x0 & 1) lazy[x0++] *= v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) + eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) + eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::IDENTITY;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left + right;
    }
};


int N;
int A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    VI unq(A, A+N+1);
    sort_unique(unq);

    auto get = [&](int x) {
	return lower_bound(unq.begin(), unq.end(), x) - unq.begin();
    };

    VI L;
    REP (i, unq.size()-1u) {
	L.push_back(unq[i+1] - unq[i]);
    }
    SegTreeLazy tree(L.begin(), L.end());

    int prv = get(A[0]);
    tree.add(0, get(A[0]), Lazy(false, 1));

    for (int i=1; i<N; i++) {
	int pos = get(A[i]);

	Mint s = tree.query(0, prv).val;

	tree.add(0, pos, Lazy(false, -s));
	if (A[i-1] <= A[i]) {

	} else {
	    tree.add(pos, prv, Lazy(true, 0));
	}

	prv = pos;
    }


    Mint ans = tree.query(0, prv).val;
    if (N % 2 == 0) {
	ans = -ans;
    }
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}