#include<cassert>
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
template<unsigned MOD> struct ModInt {
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    ModInt(int y=0) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }
    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
};
const LL MOD = 1000000009;
typedef ModInt<MOD> Mint;
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)MOD) x.x -= (unsigned)MOD; return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x -= y.x) & (1u<<31)) x.x += (unsigned)MOD; return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % (unsigned long long)MOD; return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % (unsigned long long)MOD; return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

const int MAX = 10000000;

Mint fib[MAX];
void make_fib() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2; i<MAX; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

// O(1);
Mint fast_fibonacci(int n, Mint f0=0, Mint f1=1) {
    assert(0<=n && n<MAX);
    if (n==0) return f0;
    if (n==1) return f1;
    return (fib[n-1] * f0 + fib[n] * f1);
}

struct Seg {
    int len;
    Mint sum;
    Seg() : len(0) {}
    Seg(LL val_): len(1), sum(val_) {
    }
};

Seg operator*(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    // TODO: do stuff something
    Seg z;
    z.len = x.len + y.len;
    z.sum = x.sum + y.sum;
    return z;
};
const Seg unit = Seg();

struct Lazy {
    Mint f0, f1;
    Lazy() : f0(0), f1(0) {}
    Lazy(Mint f0_, Mint f1_) : f0(f0_), f1(f1_) {}

    Lazy& operator+=(const Lazy &y) {
	// TODO: do stuff something
	f0 += y.f0;
	f1 += y.f1;
	return *this;
    }

    Lazy inc(int n) const {
	Lazy ret;
	ret.f0 = fast_fibonacci(n, f0, f1);
	ret.f1 = fast_fibonacci(n+1, f0, f1);
	return ret;
    }
};

const Lazy lazy_unit = Lazy();

Seg operator+(const Lazy &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    z.len = y.len;

    // fib(0) .. fib(n-1)
    z.sum = y.sum + fast_fibonacci(y.len + 1, x.f0, x.f1) - x.f1;
    return z;
}

// With Lazy
struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	lazy.assign(m*2, lazy_unit);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, lazy_unit);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k].inc(d[k*2].len);
	    d[k] = eval(k*2) * eval(k*2+1);
	    lazy[k] = lazy_unit;
	}
    }

    inline Seg eval(int k) {
	return (lazy[k] + d[k]);
    }

    void add(int x, int y, Lazy lz) { add(x, y, lz, 1, 0, m); }

    void add(int x, int y, Lazy lz, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k] += lz.inc(l - x); return; }

	int mid = (l+r)/2;
	add(x, y, lz, k*2, l, mid);
	add(x, y, lz, k*2+1, mid, r); 
	d[k] = eval(k*2) * eval(k*2+1);
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return eval(k);
	return query(x, y, k*2, l, (l+r)/2) * query(x, y, k*2+1, (l+r)/2, r);
	// TODO: if force is empty:
	// return lazy[k] + query(x, y, k*2, l, (l+r)/2) * query(x, y, k*2+1, (l+r)/2, r);
    }
};

int N, M;
int A[300111];

int main() {
    make_fib();
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    SegmentTree X(VI(A, A+N));

    REP ($, M) {
//	REP (i, N) eprintf("%lld ", X.query(i, i+1).sum); eprintf("\n");
	char op[9];
	int L, R;
	scanf("%s%d%d", op, &L, &R);
	L--;
	if (*op == '1') {
	    X.add(L, R, Lazy(1, 1));
	} else {
	    Seg s = X.query(L, R);
	    printf("%d\n", s.sum.getInt());
	}
    }


    return 0;
}