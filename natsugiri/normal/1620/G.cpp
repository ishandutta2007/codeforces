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

int N;
Mint dp[1<<23];
Mint dp2[1<<23];

int C[23][26];

int ORD[26][23];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	static char buf[20011];
	scanf("%s", buf);
	int len = strlen(buf);
	REP (j, len) C[i][buf[j]-'a']++;
    }

    REP (a, 26) {
	REP (i, N) ORD[a][i] = i;
	sort(ORD[a], ORD[a] + N, [&](int i, int j) {
		return C[i][a] < C[j][a];
		});
    }

    dp[(1<<N)-1] = 1;

    vector<pair<int, int> > v;
    v.reserve(N);

    REP (a, 26) {
	REP (s, 1<<N) if (dp[s].x) {

	    v.clear();
	    REP (i, N) {
		int j = ORD[a][i];
		if (s>>j&1) v.emplace_back(C[j][a], j);
	    }

	    Mint rate = dp[s];
	    dp[s] = 0;

	    int prv = -1;
	    int nxt = s;

	    for (int i=0; i<(int)v.size(); ) {
		int j = i;
		while (j < (int)v.size() && v[i].first == v[j].first) j++;

		Mint tmp = (v[i].first - prv) * rate;
		prv = v[i].first;
		dp[nxt] += tmp;

		for (int k=i; k<j; k++) nxt ^= 1 << v[k].second;

		i = j;
	    }
	}
    }

    int ALL = (1<<N)-1;
    REP (s, 1<<N) if (dp[s].x) {
	int anti = ALL ^ s;
	dp2[ALL] += dp[s];
	dp2[anti] -= dp[s];
    }

    REP (t, N) REP (s, 1<<N) if (~s>>t&1) {
	dp2[s] += dp2[s|(1<<t)];
    }

    LL ans = 0;
    REP (s, 1<<N) if (dp2[s].x) {
	LL tmp = dp2[s].x;
	LL cnt = 0, sum = 0;
	REP (i, N) if (s>>i&1) {
	    cnt++;
	    sum += i+1;
	}
	tmp *= cnt * sum;
	ans ^= tmp;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}