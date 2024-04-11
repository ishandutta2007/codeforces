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

struct Mint {
    static unsigned MOD;
    unsigned x;

    Mint() : x(0) {}
    // Mint(const Mint &y) : x(y.x) {}
    Mint(unsigned y) { if (MOD <= y) y %= MOD; x = y; }
    Mint(int y) { if (y < 0 || (long long)MOD <= y) y %= (int)MOD; if (y < 0) y += MOD; x = y; }
    Mint(unsigned long long y) { if (MOD <= y) y %= MOD; x = y; }
    Mint(long long y) { if (y < 0 || (long long)MOD <= y) y %= (long long)MOD; if (y < 0) y += MOD; x = y; }

    Mint& operator+=(const Mint &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    Mint& operator-=(const Mint &y) { if ((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    Mint& operator*=(const Mint &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    Mint& operator/=(const Mint &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    Mint operator-() const { return x? MOD - x: 0; }

    int geti() const { return x; }

    Mint inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return Mint(u);
    }

    Mint pow(long long y) const {
	Mint b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend Mint operator+(Mint x, const Mint &y) { return x += y; }
    friend Mint operator-(Mint x, const Mint &y) { return x -= y; }
    friend Mint operator*(Mint x, const Mint &y) { return x *= y; }
    friend Mint operator/(Mint x, const Mint &y) { return x /= y; }
    friend bool operator<(const Mint x, const Mint y) { return x.x < y.x; }
    friend bool operator==(const Mint x, const Mint y) { return x.x == y.x; }
    friend bool operator!=(const Mint x, const Mint y) { return x.x != y.x; }
};
unsigned Mint::MOD;

int N, M, K, P;
Mint dp[101][101][101];

Mint comb[111][111];
Mint fact[111];
void init() {
    comb[0][0] = 1;
    for (int i=1; i<=100; i++) {
	comb[i][0] = 1;
	for (int j=1; j<=100; j++) {
	    comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}
    }

    fact[0] = 1;
    for (int i=1; i<=100; i++) {
	fact[i] = fact[i-1] * i;
    }
}

Mint nCk(int n, int k) {
    return comb[n][k];
}

void MAIN() {
    scanf("%d%d%d%d", &N, &M, &K, &P);
    Mint::MOD = P;

    if (K > 50) {
	puts("0");
    } else {
	init();


	REP (m, M+1) dp[0][m][0] = 1;

	for (int n=1; n<=N; n++) {
	    dp[n][0][0] = fact[n];

	    for (int a=0; a<n; a++) {
		int b = n-1-a;

		for (int m=1; m<=M; m++) {
		    for (int x=0; x<=K; x++) if (dp[a][m-1][x].x) for (int y=0; x+y<=K; y++) {
			if (m == 1) {
			    dp[n][m][x+y+1] += dp[a][m-1][x] * dp[b][m-1][y] * nCk(n-1, a);
			} else {
			    dp[n][m][x+y] += dp[a][m-1][x] * dp[b][m-1][y] * nCk(n-1, a);
			}
		    }
		}
	    }
	}

	Mint ans = dp[N][M][K];
	printf("%d\n", ans.geti());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}