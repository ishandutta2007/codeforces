#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int M;
LL C[100011];
int mu[100011];

void MAIN() {
    REP (i, 100011) mu[i] = 2;
    mu[0] = mu[1] = 1;
    for (int i=2; i<100011; i++) if (mu[i] == 2) {
	for (int j=i; j<100011; j+=i) {
	    if (mu[j] == 2) mu[j] = -1;
	    else mu[j] = -mu[j];
	}
	LL s = (LL)i*i;
	for (LL j=s; j<100011; j+=s) {
	    mu[j] = 0;
	}
    }

    scanf("%d", &M);
    REP (i, M) {
	int a, f;
	scanf("%d%d", &a, &f);
	C[a] += f;
    }

    Mint ans = 0;

    for (int i=1; i<=100000; i++) if (mu[i]) {
	Mint sum = 0;
	Mint sum2 = 0;
	LL cnt = 0;

	for (int j=i; j<=100000; j+=i) {
	    sum += Mint(C[j]) * j;
	    sum2 += Mint(C[j]) * j * j;
	    cnt += C[j];
	}

	Mint tmp = 0;

	if (cnt >= 3) {
	    // xyd;
	    Mint p = Mint(2).pow(cnt - 3);
	    tmp += sum * sum * cnt * p;
	    tmp -= sum2 * cnt * p;
	    tmp -= sum * sum * p;
	    tmp -= sum * sum * p;
	    tmp += sum2 * p * 2;
	}

	if (cnt >= 2) {
	    // xxd;
	    Mint p = Mint(2).pow(cnt - 2);
	    tmp += sum2 * cnt * p;
	    tmp -= sum2 * p;

	    // xyx;
	    tmp += sum * sum * p;
	    tmp -= sum2 * p;
	}

	if (cnt >= 2) {
	    ans += tmp * mu[i];
	    //eprintf("%d %d %d\n", i, tmp.geti(), sum.geti());
	}
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}