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

const int MAX = 110000;
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



int N;
char S[100011];
const int SIZE = 52;
int C[SIZE];

int ord(char c) {
    if (islower(c)) return c - 'a' + 26;
    return c - 'A';
}

const int CENTER = 100011;
const int LIMIT = CENTER * 2;
Mint dp[55][LIMIT];
Mint buf[LIMIT];
Mint bug[LIMIT];
Mint H[SIZE][SIZE];


void MAIN() {
    init();

    scanf("%s", S);
    N = strlen(S);
    REP (i, N) C[ord(S[i])]++;

    dp[0][CENTER] = 1;

    REP (x, SIZE) {
	memset(dp[x+1], 0, sizeof dp[x+1]);
	for (int i=C[x]; i<LIMIT; i++) {
	    dp[x+1][i-C[x]] += dp[x][i];
	}
	if (C[x]) {
	    for (int i=0; i<LIMIT-C[x]; i++) {
		dp[x+1][i+C[x]] += dp[x][i];
	    }
	}
    }

    REP (x, SIZE) {
	memcpy(buf, dp[SIZE], sizeof buf);
	REP (i, LIMIT-C[x]*2) buf[i+C[x]*2] -= buf[i];

	H[x][x] = buf[CENTER];

	REP (y, x) {
	    memcpy(bug, buf, sizeof buf);
	    REP (i, LIMIT-C[y]*2) bug[i+C[y]*2] -= bug[i];
	    H[y][x] = bug[CENTER];
	}
    }


    Mint f = 2 * fact[N/2] * fact[N/2];
    REP (x, SIZE) f *= fact_inv[C[x]];

    REP (x, SIZE) REP (y, SIZE) {
	H[x][y] *= f;
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	x = ord(S[x]);
	y = ord(S[y]);
	if (x > y) swap(x, y);

	printf("%d\n", H[x][y].geti());
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}