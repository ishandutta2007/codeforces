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

//const LL MOD = 1000000007;
const LL MOD = 998244353;
typedef ModInt<MOD> Mint;

int N, K;

Mint calc(const VI &v) {
    int len = v.size();
    if (len == 0) return 1;
    if (*max_element(v.begin(), v.end()) == -1) {
	return Mint(K) * Mint(K-1).pow(len-1);
    }

    Mint ret = 1;
    for (int i=0; i<(int)v.size(); ) {
	int j = i+1;
	while (j < (int)v.size() && v[j] == -1) j++;

	if (v[i] == -1) {
	    ret *= Mint(K-1).pow(j);
	} else if (j == (int)v.size()) {
	    ret *= Mint(K-1).pow(j-i-1);
	} else {
	    int in = j-i-1;
	    if (v[i] == v[j]) {
		Mint a = 1, b = 0;
		REP (k, in+1) {
		    Mint na = b;
		    Mint nb = a * (K-1) + b * (K-2);
		    a = na;
		    b = nb;
		}
		ret *= a;
	    } else {
		Mint a = 1, b = 0, c = 0;
		REP (k, in+1) {
		    Mint na = b + c;
		    Mint nb = a + c;
		    Mint nc = (a+b) * (K-2) + c * (K-3);
		    a = na;
		    b = nb;
		    c = nc;
		}
		ret *= b;
	    }
	}

	i = j;
    }
    return ret;
}

int A[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    Mint ans = 1;
    REP (s, 2) {
	VI v;
	for (int i=s; i<N; i+=2) {
	    v.push_back(A[i]);
	}
	ans *= calc(v);
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}