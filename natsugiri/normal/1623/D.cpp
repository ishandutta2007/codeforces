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

Mint buf[400011][2];
int N;
int M;
int Rb, Cb, Rd, Cd;

int id(int r, int c, int dr, int dc) {
    return ((r * M + c) * 2 + (dr == 1? 0: 1)) * 2 + (dc == 1? 0: 1);
}

void MAIN() {
    int P;
    scanf("%d%d%d%d%d%d%d", &N, &M, &Rb, &Cb, &Rd, &Cd, &P);

    Mint rate = Mint(100) / (100 - P);
    Rb--;
    Cb--;
    Rd--;
    Cd--;

    int r = Rb, c = Cb;
    int sdr = 1, sdc = 1;
    if (r == 0) sdr = -1;
    if (c == 0) sdc = -1;

    int dr = sdr;
    int dc = sdc;
    int v = id(r, c, dr, dc);

    buf[v][0] = 0;
    buf[v][1] = 1;


    while (1) {
	// eprintf("%d %d %d %d -> ", r, c, dr, dc);
	int rr = r + dr;
	if (rr < 0 || N <= rr) dr = -dr;
	int cc = c + dc;
	if (cc < 0 || M <= cc) dc = -dc;

	rr = r + dr;
	cc = c + dc;
	// eprintf("%d %d %d %d\n", rr, cc, dr, dc);

	Mint nxt1, nxt0;
	if (r == Rd || c == Cd) {
	    nxt0 = buf[v][0] * rate - 1;
	    nxt1 = buf[v][1] * rate;
	} else {
	    nxt0 = buf[v][0] - 1;
	    nxt1 = buf[v][1];
	}

	int w = id(rr, cc, dr, dc);
	if (rr == Rb && cc == Cb && dr == sdr && dc == sdc) {
	    Mint ans = (buf[w][0] - nxt0) / (nxt1 - buf[w][1]);
	    printf("%d\n", ans.geti());
	    return;
	} else {
	    buf[w][0] = nxt0;
	    buf[w][1] = nxt1;
	}

	v = w;
	r = rr;
	c = cc;
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}