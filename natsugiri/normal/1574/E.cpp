#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<array>

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

int N, M, K;

int eval(int a[2]) {
    int ret = 0;
    if (a[0]) ret |= 1;
    if (a[1]) ret |= 2;
    return ret;
}

void add(int Xk[4], int X[][2], int x, int y, int t, int val) {
    Xk[eval(X[x])]--;
    X[x][(y^t)&1] += val;
    Xk[eval(X[x])]++;
}

map<pair<int, int>, int> mp;

int X[1000011][2];
int Y[1000011][2];

// 00, 01, 10, 11;
int Xk[4], Yk[4];
int Zk[2];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    Xk[0] = N;
    Yk[0] = M;

    REP ($, K) {
	int x, y, t;
	scanf("%d%d%d", &x, &y, &t);

	pair<int, int> key(x, y);
	auto it = mp.find(key);
	if (it != mp.end()) {
	    add(Xk, X, x, y, it->second, -1);
	    add(Yk, Y, y, x, it->second, -1);
	    Zk[(x^y^it->second)&1]--;
	    mp.erase(it);
	}

	if (t != -1) {
	    add(Xk, X, x, y, t, 1);
	    add(Yk, Y, y, x, t, 1);
	    Zk[(x^y^t)&1]++;
	    mp.emplace(key, t);
	}

	Mint ans = 0;
	if (Xk[3] == 0) ans += Mint(2).pow(Xk[0]);
	if (Yk[3] == 0) ans += Mint(2).pow(Yk[0]);
	if (Zk[0] == 0) ans -= 1;
	if (Zk[1] == 0) ans -= 1;

	printf("%d\n", ans.geti());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}