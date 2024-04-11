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
Mint pow2[100012];

const int MAX = 1000011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

bool _auto_init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];

    pow2[0] = 1;
    REP (i, 100011) pow2[i+1] = pow2[i] + pow2[i];

    return true;
}
const bool _auto_init_done = _auto_init();

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}
int N;
int A[100011];

Mint solve() {
    LL sum = 0;
    REP (i, N) sum += A[i];

    if (sum == 0) {
	return Mint(2).pow(N-1);
    }

    LL cur = 0;
    REP (i, N) {
	cur += A[i];
	if (cur * 2 == sum) {
	    // [0..i] 0000 [);

	}
    }

    bool FIRST = true;
    int L = 0, R = N-1;

    Mint ans = 1;
    while (1) {
	int left_zero = 0;
	while (L < R && A[L] == 0) {
	    L++;
	    left_zero++;
	}

	int right_zero = 0;
	while (L < R && A[R] == 0) {
	    R--;
	    right_zero++;
	}

	if (L == R && A[L] == 0) {
	    // center zeros
	    return ans * pow2[left_zero+2];
	}

	if (FIRST) {
	    Mint tmp = 0;
	    for (int k=0; k<=left_zero && k<=right_zero; k++) {
		tmp += nCk(left_zero, k) * nCk(right_zero, k);
	    }
	    ans *= tmp;
	    FIRST = false;
	} else {
	    Mint tmp = 1;
	    for (int s=1; s<=left_zero+1 && s<=right_zero+1; s++) {
		tmp += nCk(left_zero+1, s) * nCk(right_zero+1, s);
	    }
	    ans *= tmp;
	}

	if (L == R) {
	    return ans;
	}

	LL left_sum = A[L++];
	LL right_sum = A[R--];
	while (L <= R && left_sum != right_sum) {
	    if (left_sum < right_sum) {
		left_sum += A[L++];
	    } else {
		right_sum += A[R--];
	    }
	}

	if (L > R) {
	    if (left_sum == right_sum) {
		return ans * 2;
	    } else {
		return ans;
	    }
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    Mint ans = solve();
    printf("%d\n", ans.geti());

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}