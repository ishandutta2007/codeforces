#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
    static constexpr unsigned MOD = MOD_;
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

int N;
int M;
LL A[200011];
LL B[60];

Mint dp[60][1<<20];
Mint ans[60];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld", A+i);

    Mint mul = 1;

    REP (i, N) {
	LL x = A[i];
	bool f = false;
	REP (j, M) if (x>>j&1) {
	    if (B[j] == 0) {
		B[j] = x;
		f = true;
		break;
	    } else {
		x ^= B[j];
	    }
	}

	if (!f) mul += mul;
    }

    int HIT = 0, ZERO = 0;
    REP (j, M) {
	if (B[j]) {
	    HIT++;
	    REP (k, j) if (B[k]>>j&1) B[k] ^= B[j];
	} else {
	    ZERO++;
	}
    }

    if (HIT < ZERO) {
	eprintf("2^HIT\n");
	vector<LL> X;
	X.reserve(1<<HIT);
	X.push_back(0LL);
	REP (j, M) if (B[j]) {
	    int len = X.size();
	    REP (i, len) {
		LL tmp = X[i] ^ B[j];
		X.push_back(tmp);
	    }
	}
	EACH (e, X) ans[__builtin_popcountll(*e)] += 1;
    } else {
	eprintf("HIT^2 * 2^ZERO\n");
	dp[0][0] = 1;
	const int U = 1<<ZERO;
	REP (j, M) if (B[j]) { // *HIT;
	    int pos = 0;
	    int mask = 0;
	    REP (k, M) if (B[k] == 0) {
		if (B[j]>>k&1) {
		    mask |= 1<<pos;
		}
		pos++;
	    }

	    for (int a=HIT; a>=0; a--) {
		REP (s, U) {
		    dp[a+1][s^mask] += dp[a][s];
		}
	    }
	}

	REP (a, HIT+1) REP (s, U) {
	    ans[a + __builtin_popcount(s)] += dp[a][s];
	}
    }

    REP (j, M+1) {
	ans[j] *= mul;
	printf("%d%c", ans[j].geti(), " \n"[j==M]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}