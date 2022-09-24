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
const int MAX = 10011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

void init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}
Mint nPk(int n, int k) {
    return fact[n] * fact_inv[n-k];
}


Mint buf[2][4011][2];
Mint (*cur)[2] = buf[0];
Mint (*nxt)[2] = buf[1];

vector<Mint> solve(int H, int W, bool R[4011], bool C[4011]) {
    int limit = 0;
    REP (i, H) if (!R[i]) limit++;

    memset(cur, 0, sizeof buf[0]);
    cur[0][0] = 1;
    REP (j, W) {
	memset(nxt, 0, sizeof buf[0]);
	if (C[j]) {
	    REP (k, limit+1) {
		nxt[k][0] += cur[k][0] + cur[k][1];
	    }
	} else {
	    REP (k, limit+1) {
		nxt[k][1] += cur[k][0] + cur[k][1];
		nxt[k+1][0] += cur[k][1];
	    }
	}
	swap(cur, nxt);
    }

    vector<Mint> ret(limit+1);
    REP (k, limit+1) {
//	eprintf("%d %d\n", cur[k][0].geti(), cur[k][1].geti());
	ret[k] = cur[k][0] + cur[k][1];
    }
//    eprintf("\n");
    return ret;
}

int H, W;
int N;
bool R[4011], C[4011];

void MAIN() {
    init();

    scanf("%d%d%d", &H, &W, &N);
    REP (i, N) {
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--;
	c1--;
	r2--;
	c2--;
	R[r1] = R[r2] = true;
	C[c1] = C[c2] = true;
    }

    vector<Mint> h = solve(H, W, R, C);
    vector<Mint> v = solve(W, H, C, R);

    int c_space = 0, r_space = 0;
    REP (j, W) if (!C[j]) c_space++;
    REP (i, H) if (!R[i]) r_space++;

    Mint ans = 0;
    REP (i, v.size()) REP (j, h.size()) {
	if (i*2 + j <= r_space && i + j*2 <= c_space) {
	    ans += v[i] * h[j] * nPk(r_space - 2*i, j) * nPk(c_space - 2*j, i);
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