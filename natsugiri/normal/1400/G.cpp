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

const int MAX = 300011;
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

int N, M;
int L[300011], R[300011];
int A[21], B[21];
int C[300011];
int force[300011][45];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d%d", L+i, R+i);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
    }
    

    Mint ans = 0;
    VI take;
    REP (s, 1<<M) {
	take.clear();
	REP (t, M) if (s>>t&1) {
	    take.push_back(A[t]);
	    take.push_back(B[t]);
	}
	sort(take.begin(), take.end());
	take.erase(unique(take.begin(), take.end()), take.end());

	int low = 1, high = N;
	EACH (e, take) {
	    amax(low, L[*e]);
	    amin(high, R[*e]);
	}
	int sz = take.size();
	if (low <= high) {
	    int sgn;
	    if (__builtin_popcount(s) & 1) sgn = -1;
	    else sgn = 1;
	    force[low][sz] += sgn;
	    force[high+1][sz] -= sgn;
	}
    }

    memset(C, 0, sizeof C);
    REP (i, N) {
	C[L[i]]++;
	C[R[i]+1]--;
    }
    REP (i, N) {
	C[i+1] += C[i];
	REP (f, M*2+1) {
	    force[i+1][f] += force[i][f];
	}
    }


    for (int i=1; i<=N; i++) if (C[i] >= i) {
	REP (f, M*2+1) if (f <= i && force[i][f]) {
	    assert(f <= i && i <= C[i]);
	    Mint tmp = nCk(C[i] - f, i - f) * force[i][f];
	    ans += tmp;
	}
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}