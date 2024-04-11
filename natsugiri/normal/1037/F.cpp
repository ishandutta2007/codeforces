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
    static const unsigned static_MOD = MOD;
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
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
template<class T> struct IRXQ {
    static const int npos = -1;

    int n, g; T *d;
    IRXQ() : n(0), g(0), d(NULL) {}
    template<class Iter> IRXQ(Iter begin, Iter end) : n(0), g(0), d(0) { build(begin, end); }
    IRXQ(const IRXQ &y) : n(y.n), g(0), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRXQ(IRXQ &&y) : n(0), g(0), d(NULL) { swap(*this, y); }
    ~IRXQ() { if (n) { n = 0; delete d; d = NULL; } }
    friend void swap(IRXQ &x, IRXQ &y) { swap(x.n, y.n); swap(x.g, y.g); swap(x.d, y.d); }
    IRXQ& operator=(IRXQ y) { swap(*this, y); return *this; }

    template<class Iter> void build(Iter begin, Iter end) { // random access iterator
	n = end - begin;
	if (n == 0) return;
	g = __lg(n);
	d = new T[n*(g+1)];
	REP (i, n) { d[i] = *begin; ++begin; }
	for (int t=0, b=0; t<g; t++, b+=n) for (int i=0, j=1<<t; j<=n-(1<<t); i++, j++)
	    d[b+n+i] = (d[b+i] < d[b+j]? d[b+j]: d[b+i]);
    }

    const T at(int i) const { return d[i]; }

    const T max_v(int l, int r) const {
	int h = __lg(r - l), b = n * h;
	r -= 1<<h;
	return d[b+l] < d[b+r]? d[b+r]: d[b+l];
    }

    int max_i(int l, int r) const {
	return first_more_equal(l, max_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) > v: return i;
    // return npos;
    int first_more_than(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && !(v < d[n*t+l]))
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [l .. n-1]:
    //   if v <= at(i): return i;
    // return npos;
    int first_more_equal(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && d[n*t+l] < v)
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [r-1 .. 0]:
    //   if v < at(i): return i;
    // return npos;
    int last_more_than(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && !(v < d[n*t+r-(1<<t)]))
		r -= 1 << t;
	return r? r-1: npos;
    }

    // for i in [r-1 .. 0]:
    //   if v <= at(i): return i;
    // return npos;
    int last_more_equal(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && d[n*t+r-(1<<t)] < v)
		r -= 1 << t;
	return r? r-1: npos;
    }
};
int N, K;
int A[1000011];

Mint Ct(int len) {
    LL height = len / (K-1) + 1;
    LL bot = len - (height-1) * (K-1);
    return Mint(len + bot) * height / 2;
}
Mint C(int len, int pos) {
    return Ct(len) - Ct(pos) - Ct(len - pos - 1);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    IRXQ<int> rxq(A, A+N);
    Mint ans = 0;
    vector<pair<int, int> > Seg;
    // [0, N)
    Seg.emplace_back(0, N);
    while (!Seg.empty()) {
	int left = Seg.back().first;
	int right = Seg.back().second;
	Seg.pop_back();

	int i = rxq.max_i(left, right);
	if (left < i) Seg.emplace_back(left, i);
	if (i+1 < right) Seg.emplace_back(i+1, right);

//	eprintf("%d %d %d %d\n", left, right, A[i], C(right-left, i-left).geti());
	ans += C(right - left, i - left) * A[i];
    }

    REP (i, N) ans -= A[i];
    printf("%d\n", ans.geti());
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}