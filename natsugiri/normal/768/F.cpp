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

    static ModInt buffered_inv(const ModInt y) {
	static ModInt *inv_tbl = NULL;
	if (inv_tbl == NULL) {
	    const int n = 2000001;
	    inv_tbl = new ModInt[n];
	    inv_tbl[0] = 0; inv_tbl[1] = 1;
	    for (int i=2; i<n; i++) inv_tbl[i] = ModInt((unsigned long long)inv_tbl[MOD%i].x * (MOD-MOD/i));
	}
	return inv_tbl[y.x];
    }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

const int MAX = 1000000;
Mint inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i);

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i;
	fact_inv[i] = fact_inv[i-1] * inv[i];
    }
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

int F, W, H;
Mint calc(int fr, int wr, int hi) {
    if (F && !fr) return 0;
    if (!F && fr) return 0;
    if (W && !wr) return 0;
    if (!W && wr) return 0;
    if (F < fr) return 0;
    if (W < wr) return 0;

    LL rest = W - (LL) wr * (hi + 1);
    if (rest < 0) return 0;

    Mint ret = 1;
    // F
    if (fr) {
	ret *= nCk(F - 1, F - fr);
    }

    if (wr) {
	ret *= nCk(rest + wr - 1, rest);
    }

    return ret;
}


int main() {
    init();
    scanf("%d%d%d", &F, &W, &H);

    Mint de = 0, nu;
    REP (i, min(F, W) + 1) {
	de += calc(i, i, 0) * 2;
	de += calc(i, i+1, 0);
	de += calc(i+1, i, 0);

	nu += calc(i, i, H) * 2;
	nu += calc(i, i+1, H);
	nu += calc(i+1, i, H);
    }

//    eprintf("%d %d\n", nu.geti(), de.geti());
    printf("%d\n", (nu/de).geti());

    return 0;
}