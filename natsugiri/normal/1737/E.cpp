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

Mint powinv2[1000011];
void init() {
    powinv2[0] = 1;
    powinv2[1] = Mint(2).inv();
    for (int i=2; i<1000011; i++) powinv2[i] = powinv2[i-1] * powinv2[1];
}

int N;
Mint ans[1000011];

void slow() {
    REP (i, N) ans[i] = 0;
    vector<pair<int, int> > stk;
    REP (s, 1<<N) {
	stk.clear();
	REP (i, N) {
	    if (i == N-1 || (s>>i&1)) {
		int id = i;
		int sum = 1;
		while (!stk.empty()) {
		    if (stk.back().second > sum) {
			id = stk.back().first;
		    }
		    sum += stk.back().second;
		    stk.pop_back();
		}
		stk.emplace_back(id, sum);
	    } else {
		stk.emplace_back(i, 1);
	    }
	}

	assert(stk.size() == 1u);
	ans[stk.back().first] += powinv2[N];
    }
    REP (i, N) printf("%d\n", ans[i].geti());
}

void MAIN() {
    scanf("%d", &N);

    REP (i, N) ans[i] = 0;

    int stop = N;
    Mint total = 0;
    ans[N-1] = powinv2[(N-1)/2];

    for (int i=N-2; i>0; i--) {
	int t;
	if (i == 1) t = 1;
	else t = (i+2)/2;

	while (2*i+1 < stop) {
	    total += ans[--stop];
	}
	ans[i] = (1-total) * powinv2[t];
    }

    REP (i, N) printf("%d\n", ans[i].geti());

#ifdef LOCAL
    puts("");
    slow();
    puts("");
    puts("");
#endif
}

int main() {
    init();;
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}