#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
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

constexpr LL MOD = 31607;
using Mint = ModInt<MOD>;

const Mint BASE = Mint(1) / 10000;
int N;
int A[21][21];
Mint P[21][21];

int MASK;
int ctz[1<<21];
void init() {
    MASK = (1<<N) - 1;
    REP (s, 1<<N) if (s) ctz[s] = __builtin_ctz(s);
}

Mint dp[1<<21];
Mint dpV[1<<21];

Mint calc1(bool d1, bool d2) {
    Mint ret = 0;
    Mint total = 1;

    memset(dpV, 0, sizeof dpV);
    REP (s, 1<<N) dpV[s] = 1;

    REP (i, N) {
	Mint p = 1, q = 1;
	REP (j, N) {
	    if ((d1 && i == j) || (d2 && i+j == N-1)) {
		q *= P[i][j];
	    } else {
		p *= P[i][j];
	    }
	}
	ret = total * p * q + ret * q;

	total *= (1-p) * q;

	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	REP (s, 1<<N) if (s) {
	    int j = ctz[s];

	    if ((d1 && i == j) || (d2 && i+j == N-1)) {
		dp[s] += 1 * dp[s^(1<<j)];
	    } else {
		dp[s] += P[i][j] * dp[s^(1<<j)];
	    }
	}

	REP (s, 1<<N) {
	    dpV[s] *= q * dp[s] * (1 - dp[MASK ^ s]);
	}
    }

    dpV[0] = 0;
    dpV[MASK] = 0;

    REP (s, 1<<N) if (s && dpV[s].x) {
	if (__builtin_popcount(s) % 2 == 1) {
	    ret += dpV[s];
	} else {
	    ret -= dpV[s];
	}
    }
    return ret;
}

Mint calc2(bool d1, bool d2) {
    Mint ret = 1;

    REP (i, N) {
	REP (j, N) {
	    if ((d1 && i == j) || (d2 && i+j == N-1)) {
		ret *= P[i][j];
	    }
	}
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) scanf("%d", &A[i][j]);

#ifdef LOCALx
    N = 21;
    REP (i, N) REP (j, N) A[i][j] = rand() % 10000;
#endif

    REP (i, N) REP (j, N) P[i][j] = A[i][j] * BASE;

    init();

    Mint E = calc1(0, 0);
    Mint E10 = calc1(1, 0);
    Mint E01 = calc1(0, 1);
    Mint E11 = calc1(1, 1);

    Mint X10 = calc2(1, 0);
    Mint X01 = calc2(0, 1);
    Mint X11 = calc2(1, 1);

    Mint ans = E;
    ans -= (E10 + E01 - E11);
    ans += (X10 + X01 - X11);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}