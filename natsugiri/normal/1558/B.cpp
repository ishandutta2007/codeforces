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

int N;
Mint dp[4000011];
Mint aux[4000011];
void MAIN() {
    scanf("%d%u", &N, &Mint::MOD);

    dp[1] = 1;
    for (int i=1; i<=N; i++) {
	dp[i] += aux[i];
	aux[i+1] += aux[i];
	aux[i+1] += dp[i];
	for (int j=2; j*i<=N; j++) {
	    aux[j*i] += dp[i];
	    if (j*i+j<=N) {
		aux[j*i+j] -= dp[i];
	    }
	}
    }
    printf("%d\n", dp[N].geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}