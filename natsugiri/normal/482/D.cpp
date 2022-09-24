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
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    ModInt(int y=0) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
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
};
const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)MOD) x.x -= (unsigned)MOD; return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x -= y.x) & (1u<<31)) x.x += (unsigned)MOD; return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % (unsigned long long)MOD; return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % (unsigned long long)MOD; return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

int N;
VI G[100111];
int par[100111];
Mint dp[100111][2];

int main() {
    scanf("%d", &N);

    par[0] = -1;
    REP (i, N-1) {
	scanf("%d", par+i+1);
	par[i+1]--;
	G[par[i+1]].push_back(i+1);
    }

    for (int v=N; v--;) {
	Mint cur[2] = { 2, 0 };
	Mint even = 1;
	Mint odd[2] = { 1, 0 };
	EACH (e, G[v]) {
	    Mint nxt[2] = {};
	    nxt[0] = cur[0] * (dp[*e][0]+1) + cur[1] * dp[*e][1];
	    nxt[1] = cur[1] * (dp[*e][0]+1) + cur[0] * dp[*e][1];
	    swap(cur, nxt);

	    even *= dp[*e][0]+1;
	    nxt[0] = odd[1] * dp[*e][1] + odd[0];
	    nxt[1] = odd[0] * dp[*e][1] + odd[1];
	    swap(odd, nxt);
	}

	dp[v][1] += cur[0] - even;
	dp[v][0] += cur[1] - odd[1];
    }

    Mint ans = dp[0][0] + dp[0][1];
    printf("%d\n", ans.getInt());

    return 0;
}