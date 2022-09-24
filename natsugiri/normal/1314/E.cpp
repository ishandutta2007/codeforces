#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

// constexpr LL MOD = 1000000007;
constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

int N, K;
Mint ans;
Mint dp[2111][2111];

VI v;
VI cur, nxt;
bool rec() {
    cur = v;
    REP (k, K) {
	nxt.clear();
	int s = 0;
	REP (i, cur.size()) {
	    REP (t, cur[i]) nxt.push_back(i+1);
	    s += (i+1)*cur[i];
	}
	if (k+1 < K && s > N) return false;
	if ((int)nxt.size() > N) return false;
	reverse(nxt.begin(), nxt.end());
	swap(cur, nxt);
    }

    ans += 1;
    v.push_back(1);
    for (int b=1; b<=v.rbegin()[1]; b++) {
	v.back() = b;
	if (!rec()) break;
    }
    v.pop_back();
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &K);

    if (K == 1) {
	dp[1][0] = 1;
	for (int i=1; i<=N; i++) {
	    REP (j, N+1) {
		dp[i+1][j] += dp[i][j];
		if (j+i <= N) dp[i][j+i] += dp[i][j];
	    }
	}
	for (int j=1; j<=N; j++) ans += dp[N][j];
    } else if (K == 2) {
	dp[0][0] = 1;
	for (int b=N; b>=1; b--) {
	    REP (i, N) for (int j=0; j+(i+1)*b<=N; j++) {
		dp[i+1][j+(i+1)*b] += dp[i][j];
	    }
	}
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) ans += dp[i][j];
    } else {
	ans += 1;
	for (int b=2; b<=N; b++) {
	    v = {b};
	    rec();
	}
	v = {1, 1};
	rec();
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}