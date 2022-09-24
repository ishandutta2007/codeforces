#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
VI G[301];
int par[301];

Mint dp[311][311][2];
Mint buf[2][311][2];
Mint (*cur)[2] = buf[0];
Mint (*nxt)[2] = buf[1];

Mint Z[311];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI que;
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }


    Z[0] = 1;
    for (int limit=1; limit<=N; limit++) {
	memset(dp, 0, sizeof dp);

	REP (i, N) {
	    int v = que[N-1-i];

	    memset(cur, 0, sizeof buf[0]);
	    for (int a=1; a<=limit; a++) {
		cur[a][0] = 1;
	    }

	    // 0;
	    dp[v][0][1] = 1;
	    EACH (e, G[v]) if (*e != par[v]) {
		dp[v][0][1] *= dp[*e][0][1] + dp[*e][1][0] + dp[*e][1][1];

		memset(nxt, 0, sizeof buf[0]);
		for (int a=0; a<=limit; a++) {
		    if (a) {
			nxt[a-1][0] += cur[a-1][0] * dp[*e][a][0];
			nxt[a-1][1] += cur[a-1][1] * dp[*e][a][0];

			nxt[a-1][0] += cur[a-1][0] * dp[*e][a][1];
			nxt[a-1][1] += cur[a-1][1] * dp[*e][a][1];
		    }
		    nxt[a][0] += cur[a][0] * dp[*e][a][1];
		    nxt[a][1] += cur[a][1] * dp[*e][a][1];

		    if (a+1 <= limit) {
			nxt[a+1][1] += cur[a+1][0] * dp[*e][a][1];
			nxt[a+1][1] += cur[a+1][1] * dp[*e][a][1];
		    }
		}

		swap(cur, nxt);
	    }
	    for (int a=1; a<=limit; a++) {
		dp[v][a][0] = cur[a][0];
		dp[v][a][1] = cur[a][1];
	    }
	}

	Mint tmp = 0;
	for (int a=0; a<=limit; a++) tmp += dp[0][a][1];
	Z[limit] = tmp;
    }

    Z[0] = 1;
    Z[N+1] += 1;
    REP (i, N) {
	for (int j=i+1; j<=N; j++) Z[j] -= Z[i];
    }

    Mint ans = 0;
    REP (i, N+2) {
	// eprintf("[%d %d]\n", i-1, Z[i].geti());
	if (i == 0) {
	    ans -= 1;
	} else {
	    ans += Z[i] * (i-1);
	}
    }

    ans /= Mint(2).pow(N);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}