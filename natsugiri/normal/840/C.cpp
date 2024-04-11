#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
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

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
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

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

const int MAX = 10000;
Mint inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i);

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i;
	fact_inv[i] = fact_inv[i-1] * inv[i];
    }
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

int N;
int A[311];
//pair<int, int> P[311];

Mint dp[611][611];

int normal(int x) {
    int r = 1;
    for (int i=2; i*i<=x; i++) {
	int cnt = 0;
	while (x % i == 0) {
	    cnt++;
	    x /= i;
	}
	if (cnt & 1) r *= i;
    }
    if (x > 1) r *= x;
    return r;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	A[i] = normal(x);
    }
    sort(A, A+N);

    VI F;
    vector<Mint> FM;
    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && A[i] == A[j]) j++;
	F.push_back(j - i);
	FM.push_back(fact[j-i]);
	i = j;

//	eprintf("%d %d\n", F.back(), FM.back().geti());
    }

    int s = F[0];
    int end = F[0];
    dp[1][s-1] = FM[0];

    for (int i=1; i<(int)F.size(); i++) {
	for (int d=1; d<=F[i]; d++) {
	    Mint m = nCk(F[i] - 1, d-1) * FM[i];
	    int ad = F[i] - d;
	    if (d > s+1) continue;

	    REP (p, end) if (dp[i][p].x) REP (k, min(d+1, p+1)) { 
		if (s+1-p < d-k) continue;
		dp[i+1][p - k + ad] +=
		    dp[i][p] * nCk(p, k) * nCk(s+1-p, d-k) * m;
	    }
	}

	//REP (t, 6) eprintf("%d ", dp[i][t].geti()); eprintf("\n");
	s += F[i];
	end += F[i]-1;
    }
    //REP (t, 6) eprintf("%d ", dp[F.size()][t].geti()); eprintf("\n");

    printf("%d\n", dp[F.size()][0].geti());
}

int main() {
    init();
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}