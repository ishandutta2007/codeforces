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
    Mint(long long y) { if (y < 0 || MOD <= y) y %= (long long)MOD; if (y < 0) y += MOD; x = y; }

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

int P[10], Q[10];
void slow(int N) {
    int ans = 0;
    REP (i, N) {
	P[i] = i;
    }
    do {
	REP (i, N) {
	    Q[i] = i;
	}

	do {
	    bool lt = false;
	    REP (i, N) {
		if (P[i] < Q[i]) {
		    lt = true;
		    break;
		}
		if (P[i] > Q[i]) {
		    break;
		}
	    }

	    if (lt) {
		int cnt = 0;
		REP (i, N) for (int j=i+1; j<N; j++) {
		    if (P[i] > P[j]) cnt++;
		    if (Q[i] > Q[j]) cnt--;
		}

		if (cnt > 0) {
		    ans++;
		}
	    }

	} while (next_permutation(Q, Q+N));
    } while (next_permutation(P, P+N));

    printf("%d %d\n", N, ans);
}

const int MAX = 505;
Mint fact[MAX];
Mint comb[MAX][MAX];

bool init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;

    comb[0][0] = 1;
    for (int i=1; i<MAX; i++) {
	comb[i][0] = 1;
	for (int j=1; j<=i; j++) {
	    comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}
    }
    return true;
}

Mint nCk(int n, int k) {
    assert(0 <= k && k <= n);
    assert(n < MAX);
    return comb[n][k];
}

int N;

const int SIZE = MAX * MAX / 2;
Mint dp[MAX][SIZE+2];
Mint sums[SIZE+2];
Mint S0[SIZE+2];
Mint S1[SIZE+2];

void MAIN() {
    {
	int MOD;
	scanf("%d%d", &N, &MOD);
	Mint::MOD = MOD;
    }

    init();

    dp[1][0] = 1;
    Mint ans = 0;

    for (int len=1; len<N;) {
	REP (d, SIZE) {
	    sums[d+1] = sums[d] + dp[len][d];
	}
	REP (d, SIZE) {
	    S0[d+1] = S0[d] + sums[d];
	    S1[d+1] = S1[d] + sums[d] * d;
	}

	Mint tmp = 0;

	for (int x=1; x<SIZE; x++) {
	    int hi = min(len, x-1);
	    tmp += dp[len][x] * ((len+1-x) * (S0[x] - S0[x-hi]) + (S1[x] - S1[x-hi]));
	    //for (int d=1; d<=len && d<x; d++) {
	    //    tmp += (len+1-d) * dp[len][x] * sums[x-d];
	    //}
	}

	ans += nCk(N, len+1) * fact[N-len-1] * tmp;

	REP (d, SIZE) {
	    // dp[len+1][d] = dp[len][d-len .. d];
	    dp[len+1][d] = sums[d+1] - sums[max(0, d-len)];
	}
	len++;
    }


    printf("%d\n", ans.geti());

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}