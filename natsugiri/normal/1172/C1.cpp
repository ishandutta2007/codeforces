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

const int MAX = 100011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

void init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

int N, M;
int A[51];
int W[51];

const int BASE = 52;
Mint buf[2][BASE][BASE][BASE];
Mint (*cur)[BASE][BASE] = buf[0];
Mint (*nxt)[BASE][BASE] = buf[1];

void MAIN() {
    init();
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", W+i);

//#ifdef LOCAL
//    N = 50;
//    M = 50;
//    REP (i, N) {
//	A[i] = 0;
//	W[i] = 50;
//    }
//#endif

    int S0 = 0, S1 = 0;
    REP (i, N) {
	if (A[i] == 0) {
	    S0 += W[i];
	} else {
	    S1 += W[i];
	}
    }

    REP (i, N) {
	memset(cur, 0, sizeof buf[0]);
	const int w = W[i];

	if (A[i] == 0) {
	    S0 -= W[i];

	    REP (a, M+1) REP (b, M+1-a) REP (c, M+1-a-b) {
		cur[a][b][c] = w - a;
	    }

	    REP (t, M) {
		memset(nxt, 0, sizeof buf[0]);
		REP (a, M+1) REP (b, M+1-a) REP (c, M+1-a-b) {
		    int sum = w-a + S0-b + S1+c;

		    if (a) {
			nxt[a-1][b][c] += (w-a+1) * inv[sum+1] * cur[a][b][c];
		    }

		    if (b) {
			nxt[a][b-1][c] += (S0-b+1) * inv[sum+1] * cur[a][b][c];
		    }

		    if (c) {
			nxt[a][b][c-1] += (S1+c-1) * inv[sum-1] * cur[a][b][c];
		    }
		}
		swap(cur, nxt);
	    }

	    Mint ans = cur[0][0][0];
	    printf("%d\n", ans.geti());

	    S0 += W[i];
	} else {
	    S1 -= W[i];

	    REP (a, BASE) REP (b, BASE) REP (c, M+1-a-b) {
		cur[a][b][c] = w + a;
	    }

	    REP (t, M) {
		memset(nxt, 0, sizeof buf[0]);
		REP (a, BASE) REP (b, BASE) REP (c, M+1-a-b) {
		    int sum = w+a + S0-b + S1+c;

		    if (a) {
			nxt[a-1][b][c] += (w+a-1) * inv[sum-1] * cur[a][b][c];
		    }

		    if (b) {
			nxt[a][b-1][c] += (S0-b+1) * inv[sum+1] * cur[a][b][c];
		    }

		    if (c) {
			nxt[a][b][c-1] += (S1+c-1) * inv[sum-1] * cur[a][b][c];
		    }
		}
		swap(cur, nxt);
	    }

	    Mint ans = cur[0][0][0];
	    printf("%d\n", ans.geti());

	    S1 += W[i];
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}