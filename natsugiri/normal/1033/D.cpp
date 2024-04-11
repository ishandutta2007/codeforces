#include<map>
#include<cassert>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

const LL MOD = 998244353;
typedef ModInt<MOD> Mint;


int N;
ULL A[555];

LL pt(ULL x, int t) {
    ULL lo = 1, hi = 2e18;
    while (hi - lo > 1) {
	ULL mid = (lo + hi) / 2;
	ULL y = x;
	REP (i, t) y /= mid;
	if (y >= 1) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }
    ULL y = 1;
    REP (i, t) y *= lo;
    if (y == x) return lo;
    else return -1;
}

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%llu", A+i);

//#ifdef MYTEST
//    N = 500;
//    REP (i, N) A[i] = 7400840699802997ULL;
//    rprintf("%llu", A, A+N);
//#endif

    vector<ULL> X, Y;
    REP (i, N) {
	bool ok = false;
	for (int t=4; t>=2; t--) {
	    LL z = pt(A[i], t);
	    if (z > 0) {
		ok = true;
		REP (j, t) X.push_back(z);
		break;
	    }
	}
	if (!ok) {
	    Y.push_back(A[i]);
	}
    }

    vector<ULL> test = X;
    REP (i, Y.size()) REP (j, i) {
	if (Y[i] != Y[j]) {
	    ULL g = gcd(Y[i], Y[j]);
	    if (g > 1) test.push_back(g);
	}
    }

    sort(test.begin(), test.end());
    test.erase(unique(test.begin(), test.end()), test.end());
    map<ULL, pair<ULL, ULL> > mp;
    int cnt = 4;
    REP (i, Y.size()) {
	auto it = mp.find(Y[i]);
	if (it == mp.end()) {
	    bool ok = false;
	    EACH (e, test) {
		if (Y[i] > *e && Y[i] % *e == 0) {
		    it = mp.emplace(Y[i], make_pair(*e, Y[i] / *e)).first;
		    ok = true;
		    break;
		}
	    }
	    if (!ok) {
		it = mp.emplace(Y[i], make_pair(cnt, cnt+2)).first;
		cnt += 4;
	    }
	}
	X.push_back(it->second.first);
	X.push_back(it->second.second);
    }

    sort(X.begin(), X.end());
//#ifdef MYTEST
//    rprintf("%llu", X.begin(), X.end());
//#endif

    Mint ans = 1;
    for (int i=0; i<(int)X.size(); ) {
	int j = i;
	while (j < (int)X.size() && X[i] == X[j]) j++;
	ans *= (j-i+1);
	i = j;
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}