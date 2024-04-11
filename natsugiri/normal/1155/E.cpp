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

const LL MOD = 1000003;
typedef ModInt<MOD> Mint;

Mint M[11][11], B[11];
Mint F[11];
int r, c;
Mint d;
void GaussianEliminationMod() {
    int n = 11, m = 11;
    r = c = 0; d = 1;
    for (;r<n && c<m;) {
	int p = r;
	for (int i=r; i<n; i++) if (M[i][c].x) p = i;
	if (M[p][c] == 0) { c++; continue; }
	if (r != p) {
	    REP (j, m) swap(M[r][j], M[p][j]);
	    swap(B[r], B[p]);
	    d = MOD-d;
	}
	for (int i=0; i<n; i++) {
	    if (i == r) continue;
	    Mint a = M[i][c] / M[r][c];
	    for (int j=c; j<m; j++) M[i][j] -= a * M[r][j];
	    B[i] -= a * B[r];
	}
	r++; c++;
    }
    for (r=c=0; r<n && c<m; ) {
	if (M[r][c] == 0) { c++; continue; }
	F[c] = B[r] = B[r] / M[r][c];
	r++; c++;
    }
}

int query(int x) {
#ifdef LOCAL
    return Mint(1 + x*x + Mint(x).pow(10)).geti();
    return Mint(1 + x*x).geti();
#else
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    return x;
#endif
}

int N;

void MAIN() {
    REP (x, 11) {
	int y = query(x);
	if (y == 0) {
	    printf("! %d\n", x);
	    return;
	}
	B[x] = y;
    }

    REP (i, 11) {
	Mint p = 1;
	REP (j, 11) {
	    M[i][j] = p;
	    p *= i;
	}
    }

    GaussianEliminationMod();

    REP (x, MOD) {
	Mint p = 1;
	Mint y = 0;
	REP (j, 11) {
	    y += F[j] * p;
	    p *= x;
	}

	if (y == 0) {
	    printf("! %d\n", x);
	    return;
	}
    }

    puts("! -1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}