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

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

const int MAX = 200011;
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

LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;

struct Edge {
    int to;
    int dv, ml;
    Edge(){}
    Edge(int to_, int d_, int m_): to(to_), dv(d_), ml(m_) {}
};

VI F[200011];
void init() {
    for (int p=2; p<=200000; p++) if (F[p].empty()) {
	for (LL pp=p; pp<=200000; pp*=p) {
	    for (LL i=pp; i<=200000; i+=pp) {
		F[i].push_back(p);
	    }
	}
    }
}

vector<Edge> G[200011];
int C[200011];
int D[200011];

void add(int x, int sgn) {
    EACH (e, F[x]) {
	C[*e] += sgn;
	amax(D[*e], C[*e]);
    }
}

void dfs(int v, int p) {
    EACH (e, G[v]) if (e->to != p) {
	add(e->dv, 1);
	add(e->ml, -1);
	dfs(e->to, v);
	add(e->dv, -1);
	add(e->ml, 1);
    }
}

Mint val[200011];
void dfs2(int v, int p) {
    EACH (e, G[v]) if (e->to != p) {
	val[e->to] = val[v] * e->ml * inv[e->dv];
	dfs2(e->to, v);
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();

    memset(C, 0, sizeof (int)*(N+1));
    memset(D, 0, sizeof (int)*(N+1));

    REP (i, N-1) {
	int a, b, x, y;
	scanf("%d%d%d%d", &a, &b, &x, &y);
	a--; b--;

	int g = gcd(x, y);
	x /= g;
	y /= g;

	// a/b == x/y;
	G[a].emplace_back(b, x, y);
	G[b].emplace_back(a, y, x);
    }

    dfs(0, 0);
    val[0] = 1;
    for (int i=1; i<=N; i++) {
	REP (t, D[i]) val[0] *= i;
    }

    dfs2(0, 0);

    Mint ans = 0;
    REP (i, N) ans += val[i];
    printf("%d\n", ans.geti());
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}