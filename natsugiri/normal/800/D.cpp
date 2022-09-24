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
int N;
int A[MAX + 11];
Mint Z[MAX][4];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) {
	int a = A[i];
	Z[a][0] += 1;
	Z[a][1] += a;
	Z[a][2] += Mint(a) * Mint(a);
    }

    int ten = 1;
    REP (d, 6) {
	for (int i=MAX; i--;) {
	    if (i / ten % 10) {
		REP (j, 3) Z[i - ten][j] += Z[i][j];
	    }
	}

	ten *= 10;
    }

    REP (i, MAX) {
	if (Z[i][0].x == 1) {
	    Z[i][3] = Z[i][2];
	} else if (Z[i][0].x == 2) {
	    Z[i][3] = Z[i][1] * Z[i][1] + Z[i][2];
	} else if (Z[i][0].x > 2) {
	    Mint y = Mint(2).pow(Z[i][0].x - 2);
	    Mint x = y * 2;
	    Z[i][3] = (x - y) * Z[i][2] + y * Z[i][1] * Z[i][1];
	}
    }
    ten = 1;
    REP (d, 6) {
	REP (i, MAX) {
	    if (i / ten % 10) {
		Z[i - ten][3] -= Z[i][3];
	    }
	}

	ten *= 10;
    }

//    REP (i, MAX) if (Z[i][3].x)
//	eprintf("%d %d %lld\n", i, Z[i][3].geti(), (LL)i*Z[i][3].geti());

    LL ans = 0;
    REP (i, MAX) ans ^= (LL)i * (LL)Z[i][3].geti();
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}