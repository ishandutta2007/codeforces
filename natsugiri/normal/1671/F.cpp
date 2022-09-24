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

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;
const int MAX = 1000011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

bool _auto_init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];
    return true;
}
const bool _auto_init_done = _auto_init();

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}
Mint nCk_naive(int n, int k) {
    k = min(k, n-k);
    Mint nu = 1;
    REP (i, k) {
	nu *= n - i;
    }
    return nu * fact_inv[k];
}

// int A[15];
// int H[12][12][14];
// void rec(int I, int mask, int K, int X) {
//     if (K > 11) return;
//     if (X > 11) return;
// 
//     assert(I <= 13);
//     if (__builtin_popcount(mask + 1) == 1) {
// 	// eprintf("%d %d %d\n", K, X, I);
// 	H[K][X][I] += 1;
// 
//     } else {
// 	REP (i, 13) if (~mask>>i&1) {
// 	    A[I] = i;
// 	    rec(I+1, mask|(1<<i), K + __builtin_popcount(mask >> i), X + (A[I-1] > i? 1: 0));
// 	}
//     }
// }

const int KXIH[148][4] = {
{1, 1, 2, 1},
{2, 1, 3, 2},
{3, 1, 4, 3},
{3, 2, 3, 1},
{3, 2, 4, 1},
{4, 1, 4, 1},
{4, 1, 5, 4},
{4, 2, 4, 4},
{4, 2, 5, 4},
{5, 1, 5, 2},
{5, 1, 6, 5},
{5, 2, 4, 3},
{5, 2, 5, 12},
{5, 2, 6, 10},
{5, 3, 5, 2},
{5, 3, 6, 1},
{6, 1, 5, 2},
{6, 1, 6, 3},
{6, 1, 7, 6},
{6, 2, 5, 12},
{6, 2, 6, 28},
{6, 2, 7, 20},
{6, 3, 4, 1},
{6, 3, 5, 4},
{6, 3, 6, 13},
{6, 3, 7, 6},
{7, 1, 6, 4},
{7, 1, 7, 4},
{7, 1, 8, 7},
{7, 2, 5, 9},
{7, 2, 6, 35},
{7, 2, 7, 55},
{7, 2, 8, 35},
{7, 3, 5, 6},
{7, 3, 6, 29},
{7, 3, 7, 50},
{7, 3, 8, 21},
{7, 4, 6, 1},
{7, 4, 7, 3},
{7, 4, 8, 1},
{8, 1, 6, 3},
{8, 1, 7, 6},
{8, 1, 8, 5},
{8, 1, 9, 8},
{8, 2, 5, 3},
{8, 2, 6, 35},
{8, 2, 7, 80},
{8, 2, 8, 96},
{8, 2, 9, 56},
{8, 3, 5, 6},
{8, 3, 6, 41},
{8, 3, 7, 118},
{8, 3, 8, 145},
{8, 3, 9, 56},
{8, 4, 6, 4},
{8, 4, 7, 18},
{8, 4, 8, 26},
{8, 4, 9, 8},
{9, 1, 6, 1},
{9, 1, 7, 6},
{9, 1, 8, 8},
{9, 1, 9, 6},
{9, 1, 10, 9},
{9, 2, 6, 30},
{9, 2, 7, 95},
{9, 2, 8, 155},
{9, 2, 9, 154},
{9, 2, 10, 84},
{9, 3, 5, 4},
{9, 3, 6, 44},
{9, 3, 7, 186},
{9, 3, 8, 358},
{9, 3, 9, 350},
{9, 3, 10, 126},
{9, 4, 6, 7},
{9, 4, 7, 48},
{9, 4, 8, 124},
{9, 4, 9, 126},
{9, 4, 10, 36},
{9, 5, 8, 3},
{9, 5, 9, 4},
{9, 5, 10, 1},
{10, 1, 7, 6},
{10, 1, 8, 9},
{10, 1, 9, 10},
{10, 1, 10, 7},
{10, 1, 11, 10},
{10, 2, 6, 17},
{10, 2, 7, 101},
{10, 2, 8, 207},
{10, 2, 9, 268},
{10, 2, 10, 232},
{10, 2, 11, 120},
{10, 3, 6, 45},
{10, 3, 7, 230},
{10, 3, 8, 616},
{10, 3, 9, 898},
{10, 3, 10, 742},
{10, 3, 11, 252},
{10, 4, 5, 1},
{10, 4, 6, 7},
{10, 4, 7, 85},
{10, 4, 8, 313},
{10, 4, 9, 552},
{10, 4, 10, 448},
{10, 4, 11, 120},
{10, 5, 7, 2},
{10, 5, 8, 16},
{10, 5, 9, 48},
{10, 5, 10, 43},
{10, 5, 11, 10},
{11, 1, 7, 2},
{11, 1, 8, 11},
{11, 1, 9, 12},
{11, 1, 10, 12},
{11, 1, 11, 8},
{11, 1, 12, 11},
{11, 2, 6, 8},
{11, 2, 7, 94},
{11, 2, 8, 250},
{11, 2, 9, 389},
{11, 2, 10, 427},
{11, 2, 11, 333},
{11, 2, 12, 165},
{11, 3, 6, 30},
{11, 3, 7, 260},
{11, 3, 8, 859},
{11, 3, 9, 1654},
{11, 3, 10, 1967},
{11, 3, 11, 1428},
{11, 3, 12, 462},
{11, 4, 6, 11},
{11, 4, 7, 113},
{11, 4, 8, 567},
{11, 4, 9, 1404},
{11, 4, 10, 1887},
{11, 4, 11, 1302},
{11, 4, 12, 330},
{11, 5, 7, 4},
{11, 5, 8, 53},
{11, 5, 9, 204},
{11, 5, 10, 357},
{11, 5, 11, 252},
{11, 5, 12, 55},
{11, 6, 9, 1},
{11, 6, 10, 6},
{11, 6, 11, 5},
{11, 6, 12, 1},
};

Mint dp[12][12][12][111];

void init() {
    dp[0][0][0][0] = 1;
    REP (t, 148) {
	int k = KXIH[t][0];
	int x = KXIH[t][1];
	int i = KXIH[t][2];
	int h = KXIH[t][3];
	for (int ak=10; ak>=0; ak--) REP (ax, 11) REP (am, 11) REP (ai, 110) if (dp[ak][ax][am][ai].x) {
	    Mint hh = 1;
	    for (int m=1; m<=11; m++) {
		int bk = ak + k*m;
		int bx = ax + x*m;
		int bm = am + m;
		int bi = ai + i*m;
		hh *= h;
		if (bk <= 11 && bx <= 11) {
		    assert(bi < 111);
		    assert(bm < 12);
		    dp[bk][bx][bm][bi] += dp[ak][ax][am][ai] * hh * nCk(bm, m);
		}

	    }
	}
    }

//    for (int i=1; i<13; i++) {
//	A[0] = i;
//	rec(1, 1<<i, 0, 0);
//    }
//
//    dp[0][0][0][0] = 1;
//    int c = 0;
//    REP (k, 12) {
//	REP (x, 12) {
//	    REP (i, 14) if (H[k][x][i]) {
//		c++;
//		eprintf("{%d, %d, %d, %d},\n", k, x, i, H[k][x][i]);
//		for (int ak=10; ak>=0; ak--) REP (ax, 11) REP (am, 11) REP (ai, 110) if (dp[ak][ax][am][ai].x) {
//		    for (int m=1; m<=11; m++) {
//			int bk = ak + k*m;
//			int bx = ax + x*m;
//			int bm = am + m;
//			int bi = ai + i*m;
//			if (bk <= 11 && bx <= 11) {
//			    assert(bi < 111);
//			    assert(bm < 12);
//			    dp[bk][bx][bm][bi] += dp[ak][ax][am][ai] * Mint(H[k][x][i]).pow(m) * nCk(bm, m);
//			}
//		    }
//		}
//	    }
//	    int s = 0;
//	    REP (i, 14) s += H[k][x][i];
//	    if (s) {
////		printf("%d %d : ", k, x);
////		rprintf("%d", H[k][x], H[k][x] + 14);
//	    }
//	}
//    }
//    printf("cnt = %d\n", c);
}

void MAIN() {
    int N, K, X;
    scanf("%d%d%d", &N, &K, &X);

    Mint ans = 0;
    REP (m, 12) REP (i, 111) if (i <= N && dp[K][X][m][i].x) {
	ans += dp[K][X][m][i] * nCk_naive(m + (N-i), m);
    }

    printf("%d\n", ans.geti());
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}