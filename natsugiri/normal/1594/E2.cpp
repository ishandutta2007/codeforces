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

constexpr LL MOD = 1000000007;
using Mint = ModInt<MOD>;

int K;

// 012345
// WRBGOY
int get_index(char c) {
    static char x[] = "wrbgoy";
    REP (i, 6) if (x[i] == c) return i;
    assert(false);
    return -1;
}

LL bitrev(LL v) {
    LL r = 0;
    REP (i, K+1) {
	r *= 2;
	if (v>>i&1) r |= 1;
    }
    return r;
}

map<LL, int> mp;

void ADD(LL v, int color) {
    mp[v] = color;
    while (v > 1) {
	v /= 2;
	auto it = mp.find(v);
	if (it == mp.end()) {
	    mp[v] = -1;
	}
    }
}

vector<pair<int, int> > X;

using Arr = array<Mint, 6>;
Arr rec(LL v, int depth) {
    auto it = mp.find(v);
    if (it == mp.end()) {
	Mint tmp = Mint(4).pow((1LL<<(K - depth))-2);
	Arr arr = Arr();
	REP (c, 6) arr[c] = tmp;
	return arr;

    } else if (depth+1 == K) {
	Arr arr = Arr();
	if (it->second == -1) {
	    REP (c, 6) arr[c] = 1;
	} else {
	    arr[it->second] = 1;
	}
	return arr;

    } else {
	Arr left = rec(v*2, depth+1);
	Arr right = rec(v*2+1, depth+1);
	Mint lsum = 0, rsum = 0;
	REP (c, 6) {
	    lsum += left[c];
	    rsum += right[c];
	}

	Arr arr = Arr();
	REP (c, 6) arr[c] = lsum * rsum;

	REP (c, 6) REP (d, 6) {
	    Mint tmp = left[c] * right[d];
	    if (c == d || c + d == 5) {
		arr[c] -= tmp;
		arr[5-c] -= tmp;
	    } else {
		arr[c] -= tmp;
		arr[d] -= tmp;
		arr[5-c] -= tmp;
		arr[5-d] -= tmp;
	    }
	}

	if (it->second != -1) {
	    REP (c, 6) {
		if (c != it->second) arr[c] = 0;
	    }
	}

	return arr;
    }
}

void MAIN() {
    int N;
    scanf("%d%d", &K, &N);
    REP (i, N) {
	LL v;
	static char buf[111];
	scanf("%lld%s", &v, buf);
	ADD(v, get_index(*buf));
    }

    Arr arr = rec(1, 0);

    Mint ans = 0;
    REP (c, 6) ans += arr[c];
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}