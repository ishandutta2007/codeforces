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

template<unsigned MOD, unsigned ROOT> struct NTT {
    typedef ModInt<MOD> Mint;

    static void ntt(vector<Mint> &x, const int inverse=false) {
	int n = x.size(); // n == 1<<k;
	static vector<Mint> y, e, er;
	if (n != (int)e.size()) {
	    y.resize(n); e.resize(n); er.resize(n);
	    e[0] = 1; e[1] = Mint(ROOT).pow((MOD-1)/n);
	    er[0] = 1; er[1] = e[1].inv();
	    for (int i=2; i<n; i++) e[i] = e[i-1] * e[1];
	    for (int i=2; i<n; i++) er[i] = er[i-1] * er[1];
	}
	if (inverse) swap(e, er);
	int nn = n, s = 1, eo = 0;
	for (; nn>1;) {
	    const int m = nn / 2;
	    for (int p=0; p<m; p++) {
		Mint wp = e[p*(n/nn)];
		for (int q=0; q<s; q++) {
		    Mint a = x[q+s*p];
		    Mint b = x[q+s*(p+m)];
		    y[q+s*(p+p)] = a + b;
		    y[q+s*(p+p+1)] = (a - b) * wp;
		}
	    }
	    nn = m; s += s; eo ^= 1;
	    swap(x, y);
	}
	if (eo) {
	    for (int q=0; q<s; q++) y[q] = x[q];
	    swap(x, y);
	}
	if (inverse) {
	    swap(e, er);
	    Mint d = Mint(n).inv();
	    for (int i=0; i<n; i++) x[i] = x[i] * d;
	}
    }

    static vector<unsigned> convolution(const vector<unsigned> &f, const vector<unsigned> &g) {
	int sz = 1;
	while (sz < (int)(f.size() + g.size())) sz *= 2;
	static vector<Mint> f1, g1;
	f1.resize(sz); fill(f1.begin(), f1.end(), 0);
	g1.resize(sz); fill(g1.begin(), g1.end(), 0);
	REP (i, f.size()) f1[i] = f[i];
	REP (i, g.size()) g1[i] = g[i];
	ntt(f1);
	ntt(g1);
	REP (i, sz) f1[i] *= g1[i];
	ntt(f1, true);
	vector<unsigned> ret(f.size() + g.size());
	REP (i, ret.size()) ret[i] = f1[i].x;
	return ret;
    }
};

using Mint = ModInt<998244353>;

void MAIN() {
    const int SIZE = 1<<20;
    int N, K;
    vector<Mint> x(SIZE);

    using ntt = NTT<998244353, 3>;

    scanf("%d%d", &N, &K);
    REP (i, K) {
	int t;
	scanf("%d", &t);
	x[t] += 1;
    }

    ntt::ntt(x);
    REP (i, SIZE) x[i] = x[i].pow(N/2);
    ntt::ntt(x, true);

    Mint ans = 0;
    REP (i, SIZE) ans += x[i] * x[i];
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}