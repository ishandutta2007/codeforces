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
const int MAX = 1000011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

bool _auto_init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];
    return true;
}
const bool _auto_init_done = _auto_init();

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N;
LL L, R;

struct Data {
    LL idx;
    LL both, posi, nega;
    Data() {}
    Data(LL i_, LL b_, LL p_, LL n_): idx(i_), both(b_), posi(p_), nega(n_) {}

    bool operator<(const Data &o) const {
	return idx < o.idx;
    }
};

void MAIN() {
    scanf("%d%lld%lld", &N, &L, &R);

    vector<pair<LL, LL> > both, posi, nega;
    vector<Data> D;
    for (int i=1; i<=N; i++) {
	// L <= i - X <= R;
	// -R <= -i + X <= -L;
	// 1 <= X <= i-L;
	// L <= i + X <= R;
	// 1 <= X <= R-i;
	
	if (i-L < R-i) {
	    D.emplace_back(1, 1, 0, 0);
	    D.emplace_back(i-L+1, -1, 1, 0);
	    D.emplace_back(R-i+1, 0, -1, 0);
	} else {
	    D.emplace_back(1, 1, 0, 0);
	    D.emplace_back(R-i+1, -1, 0, 1);
	    D.emplace_back(i-L+1, 0, 0, -1);
	}
    }

    sort(D.begin(), D.end());
    int last = 0;
    for (int i=1; i<(int)D.size(); i++) {
	if (D[last].idx == D[i].idx) {
	    D[last].both += D[i].both;
	    D[last].posi += D[i].posi;
	    D[last].nega += D[i].nega;
	} else {
	    D[++last] = D[i];
	}
    }

    ++last;
    D.resize(last);

    for (int i=0; i+1<last; i++) {
	D[i+1].both += D[i].both;
	D[i+1].posi += D[i].posi;
	D[i+1].nega += D[i].nega;
    }

    assert(D.back().both == 0);
    assert(D.back().posi == 0);
    assert(D.back().nega == 0);

    LL ma = 0;
    REP (i, D.size()) {
	LL b = D[i].both;
	LL p = D[i].posi;
	LL n = D[i].nega;
	LL tmp = 0;
	LL all = b+p+n;
	LL half = all/2;
	LL rest = all - half;
	
	amax(tmp, p * (b + n));
	amax(tmp, n * (b + p));
	if (half <= p+b && rest <= n+b) amax(tmp, half * rest);
	if (rest <= p+b && half <= n+b) amax(tmp, half * rest);
	amax(ma, tmp);
    }

    Mint ans = 0;
    VI W;
    REP (i, D.size()-1u) {
	LL b = D[i].both;
	LL p = D[i].posi;
	LL n = D[i].nega;

	LL all = b+p+n;
	LL half = all/2;
	LL rest = all - half;
	
	W.clear();
	if (p * (b+n) == ma) W.emplace_back(p);
	if ((p+b) * n == ma) W.emplace_back(p+b);
	if (half * rest == ma) {
	    if (half <= p+b && rest <= n+b) W.emplace_back(half);
	    if (rest <= p+b && half <= n+b) W.emplace_back(rest);
	}

	if (!W.empty()) {
	    sort_unique(W);
	    Mint tmp = 0;
	    EACH (e, W) {
		tmp += nCk(b, *e - p);
	    }
	    tmp *= D[i+1].idx - D[i].idx;
	    ans += tmp;
	}
    }


    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}