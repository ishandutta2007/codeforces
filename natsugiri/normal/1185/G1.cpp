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

const LL MOD = 1000000007;
//const LL MOD = 998244353;
typedef ModInt<MOD> Mint;

int N, T;
Mint fact[55];

VI P[3];
Mint cnt[18][26][51][3];
Mint dp[3][51][2511];
int sum[3];

void MAIN() {
    fact[0] = 1;
    for (int i=1; i<55; i++) fact[i] = fact[i-1] * i;

    scanf("%d%d", &N, &T);
    REP (i, N) {
	int t, g;
	scanf("%d%d", &t, &g);
	g--;
	P[g].push_back(t);
    }

    if (P[0].size() > P[1].size()) swap(P[0], P[1]);
    if (P[1].size() > P[2].size()) swap(P[1], P[2]);
    if (P[0].size() > P[1].size()) swap(P[0], P[1]);

    REP (k, 3) {
	EACH (e, P[k]) sum[k] += *e;

	dp[k][0][0] = 1;
	EACH (e, P[k]) {
	    for (int a = P[k].size(); a>=0; a--) for (int j=T; j>=0; j--) if (dp[k][a][j].x) {
		dp[k][a+1][j+*e] += dp[k][a][j];
	    }
	}
    }

    cnt[1][0][0][0] = 1;
    cnt[0][1][0][1] = 1;
    cnt[0][0][1][2] = 1;
    REP (a, P[0].size()+1) REP (b, P[1].size()+1) REP (c, P[2].size()+1) {
	if (a+1 <= (int)P[0].size()) cnt[a+1][b][c][0] += cnt[a][b][c][1] + cnt[a][b][c][2];
	if (b+1 <= (int)P[1].size()) cnt[a][b+1][c][1] += cnt[a][b][c][0] + cnt[a][b][c][2];
	if (c+1 <= (int)P[2].size()) cnt[a][b][c+1][2] += cnt[a][b][c][0] + cnt[a][b][c][1];
    }

    Mint ans = 0;
    REP (a, P[0].size()+1) REP (i, sum[0]+1) if (dp[0][a][i].x) {
	REP (b, P[1].size()+1) REP (j, min(sum[1]+1, T-i+1)) if (dp[1][b][j].x) {
	    int k = T-i-j;
	    REP (c, P[2].size()+1) if (dp[2][c][k].x) {
		ans += (cnt[a][b][c][0] + cnt[a][b][c][1] + cnt[a][b][c][2])
		    * dp[0][a][i]
		    * dp[1][b][j] 
		    * dp[2][c][k] 
		    * fact[a] * fact[b] * fact[c];
	    }
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