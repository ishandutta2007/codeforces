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
    static const unsigned MOD = MOD_;
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

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
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

vector<pair<int, int> > G[200011];
int par[200011];
Mint p_dead[200011];
Mint v_dead[200011];
Mint both_dead[200011];
Mint eat_p[200011];
Mint eat_v[200011];

void bfs() {
    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    int w = e->second;
	    if (w == par[v]) continue;
	    par[w] = v;
	    ord.push_back(w);
	}
    }

    REP (i_, N) {
	int v = ord[N - 1 - i_];
	if (v == 0) break;

	Mint a0 = 1;
	Mint a1 = 0;
	int st = 0;
	EACH (e, G[v]) {
	    int w = e->second;
	    if (w == par[v]) {
		st = 1;
	    } else if (st == 0) {
		Mint n0 = a0 * (v_dead[w] + eat_v[w]);
		Mint n1 = a0 * eat_p[w] + a1 * (p_dead[w] + both_dead[w]);
		a0 = n0;
		a1 = n1;
	    } else {
		a1 = a1 * (p_dead[w] + both_dead[w]);
	    }
	}
	v_dead[v] = a1;
	both_dead[v] = v_dead[v];

	
	st = 0;
	a0 = 1;
	a1 = 0;
	EACH (e, G[v]) {
	    int w = e->second;
	    if (w == par[v]) {
		st = 1;
	    } else if (st == 0) {
		a0 = a0 * (v_dead[w] + eat_v[w]);
	    } else {
		Mint n0 = a0 * (v_dead[w] + eat_v[w]);
		Mint n1 = a0 * eat_p[w] + a1 * (p_dead[w] + both_dead[w]);
		a0 = n0;
		a1 = n1;
	    }
	}
	eat_p[v] = a0 + a1;
	p_dead[v] = eat_p[v];

	a0 = 1;
	st = 0;
	EACH (e, G[v]) {
	    int w = e->second;
	    if (w == par[v]) {
		st = 1;
	    } else if (st == 0) {
		a0 = a0 * (v_dead[w] + eat_v[w]);
	    } else {
		a0 = a0 * (p_dead[w] + both_dead[w]);
	    }
	}
	eat_v[v] = a0;
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].emplace_back(i, y);
	G[y].emplace_back(i, x);
    }
    REP (i, N) sort(G[i].begin(), G[i].end());

    bfs();

    Mint a0 = 1, a1 = 0;
    EACH (e, G[0]) {
	int w = e->second;
	Mint n0 = a0 * (v_dead[w] + eat_v[w]);
	Mint n1 = a0 * eat_p[w] + a1 * (p_dead[w] + both_dead[w]);
	a0 = n0;
	a1 = n1;
    }
    Mint ans = a0 + a1;
    printf("%d\n", ans.geti());

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}