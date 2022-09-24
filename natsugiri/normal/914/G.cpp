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
template<class T> void fwht(T *x, const int n) {
    static T *y = NULL; static int y_len = 0;
    if (y_len < n) {
	if (y) delete[] y;
	y_len = n;
	y = new T[y_len];
    }
    int nn = n, s = 1, eo = 0;
    for (; nn>1;) {
	const int m = nn >> 1;
	for (int p=0; p<m; p++) {
	    for (int q=0; q<s; q++) {
		const T a = x[q + s * p];
		const T b = x[q + s * (p + m)];
		y[q + s * (p + p)] = a + b;
		y[q + s * (p + p + 1)] = a - b;
	    }
	}
	nn = m; s += s; eo ^= 1;
	swap(x, y);
    }
    if (eo) {
	for (int q=0; q<s; q++) y[q] = x[q];
	swap(x, y);
    }
}

int N;
const int SIZE = 1 << 17;

const Mint invSize = Mint(1)/SIZE;
Mint Pxor[SIZE];
Mint Sa[SIZE], Sor[SIZE];
Mint G[SIZE];

Mint fib[SIZE];

void Zsuper(Mint s[]) {
    REP (t, 17) REP (i, SIZE) if (~i>>t&1) s[i|(1<<t)] += s[i];
}
void Zsub(Mint s[]) {
    REP (t, 17) REP (i, SIZE) if (~i>>t&1) s[i] += s[i|(1<<t)];
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);

	Sa[x] += 1;
	Pxor[x] += 1;
    }

    fib[1] = 1;
    REP (i, SIZE-2) fib[i+2] = fib[i] + fib[i+1];

    REP (i, SIZE) {
	for (int sub=i; ; sub=i&(sub-1)) {
	    Sor[i] += Pxor[sub] * Pxor[i-sub];
	    if (sub == 0) break;
	}
    }


    fwht(Pxor, SIZE);
    REP (i, SIZE) Pxor[i] *= Pxor[i];
    fwht(Pxor, SIZE);
    REP (i, SIZE) Pxor[i] *= invSize;

    REP (i, SIZE) {
	Sa[i] = fib[i] * Sa[i];
	Sor[i] = fib[i] * Sor[i];
	Pxor[i] = fib[i] * Pxor[i];
    }
    Zsub(Sa);
    Zsub(Sor);
    Zsub(Pxor);


    REP (i, SIZE) G[i] = Sa[i] * Sor[i] * Pxor[i];
    REP (t, 17) for (int i=SIZE; i--;) if (~i>>t&1) G[i] -= G[i|(1<<t)];

    Mint ans = 0;
    REP (t, 17) ans += G[1<<t];
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}