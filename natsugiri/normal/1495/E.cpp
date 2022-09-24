#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<deque>
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

Mint seed = 0;
Mint base = 0;
LL rnd() {
    LL ret = seed.geti();
    seed = (seed * base + 233);
    return ret;
}


int N, M;
vector<LL> T, A;


int ans[5000011];

void MAIN() {
    scanf("%d", &N);
    scanf("%d", &M);

    int prv = 0;
    REP (i, M) {
	int p, k, b, w;
	scanf("%d%d%d%d", &p, &k, &b, &w);
	seed = b;
	base = w;

	REP (j, p-prv) {
	    T.push_back(rnd() % 2 + 1);
	    A.push_back(rnd() % k + 1);
	}

	prv = p;
    }

    //rprintf("%lld", A.begin(), A.end());
    //rprintf("%lld", T.begin(), T.end());

    LL sumFirst = 0, sumSecond = 0;
    REP (i, N) {
	if (T[i] == T[0]) sumFirst += A[i];
	else sumSecond += A[i];
    }

    if (sumFirst > sumSecond) {
	LL rest = 0;
	ans[0]++;
	A[0]--;
	REP (t, N*2) {
	    int i = t % N;
	    if (T[i] == T[0]) {
		LL g = min(rest, A[i]);
		ans[i] += g;
		rest -= g;
		A[i] -= g;
	    } else {
		rest += A[i];
		ans[i] += A[i];
		A[i] = 0;
	    }
	}
	assert(rest == 0);
    } else {
	LL rest = 0;
	REP (t, N*2) {
	    int i = t % N;
	    if (T[i] != T[0]) {
		LL g = min(rest, A[i]);
		ans[i] += g;
		rest -= g;
		A[i] -= g;
	    } else {
		rest += A[i];
		ans[i] += A[i];
		A[i] = 0;
	    }
	}
	assert(rest == 0);
    }

    //rprintf("%d", ans, ans+N);

    Mint out = 1;
    REP (i, N) {
	LL tmp = ans[i] ^ ((LL)(i+1)*(i+1));
	out *= tmp + 1;
    }

    printf("%d\n", out.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}