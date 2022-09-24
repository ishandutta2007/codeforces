#include<array>
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

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

int N, M;
int A[100011], B[100011], W[100011];

bool in[100011], tri[100011];
int X[100011];
int head[100011];

VI G[100011];

unsigned normal[1<<15];
unsigned push[1<<15][32];
int rnk[1<<15];
vector<unsigned> value;

void build_push() {
    for (unsigned x_=0; x_<(1<<15); x_++) {
	unsigned x = x_;
	if (~x>>4&1 && x&15) continue;
	if (~x>>8&1 && x>>5&7) continue;
	if (~x>>11&1 && x>>9&3) continue;
	if (~x>>13&1 && x>>12&1) continue;
	unsigned y = x>>5&15;
	if (y&8) {
	    if (x&8) x ^= y;
	}
	y = x>>9&7;
	if (y&4) {
	    if (x&4) x ^= y;
	    if (x>>5&4) x ^= y<<5;
	}
	y = x>>12&3;
	if (y&2) {
	    if (x&2) x ^= y;
	    if (x>>5&2) x ^= y<<5;
	    if (x>>9&2) x ^= y<<9;
	}
	y = x>>14&1;
	if (y) {
	    if (x&1) x ^= y;
	    if (x>>5&1) x ^= y<<5;
	    if (x>>9&1) x ^= y<<9;
	    if (x>>12&1) x ^= y<<12;
	}
	normal[x_] = x;
    }

    memset(rnk, -1, sizeof rnk);
    for (unsigned x_=0; x_<(1<<15); x_++) if (normal[x_] == x_) {
	rnk[x_] = value.size();
	value.push_back(x_);
	for (unsigned w_=0; w_<32; w_++) {
	    unsigned x = x_, w = w_;
	    do {
		if (w&16) {
		    if (x&16) w ^= x&31;
		    else { x |= w; break; }
		}
		if (w&8) {
		    if (x>>5&8) w ^= x>>5&15;
		    else { x |= w<<5; break; }
		}
		if (w&4) {
		    if (x>>9&4) w ^= x>>9&7;
		    else { x |= w<<9; break; }
		}
		if (w&2) {
		    if (x>>12&2) w ^= x>>12&3;
		    else { x |= w<<12; break; }
		}
		if (w&1) {
		    if (x>>14&1) w ^= x>>14&1;
		    else { x |= w<<14; break; }
		}
		assert(w == 0);
		x = ~0;
	    } while (0);

	    if (x != ~0u) {
		x = normal[x];
	    }
	    push[x_][w_] = x;
	}
    }

    eprintf("%d\n", (int)value.size());
}

unsigned C[100011];
bool zero[100011];

int depth[100011];
Mint cur[374];
Mint nxt[374];

void MAIN() {
    build_push();

    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	a--; b--;
	if (a > b) swap(a, b);
	if (a == 0) in[b] = true;
	A[i] = a;
	B[i] = b;
	W[i] = w;
    }

    REP (i, M) if (A[i] == 0) X[B[i]] = W[i];
    REP (i, M) if (A[i] != 0 && in[A[i]] && in[B[i]]) {
	tri[A[i]] = true;
	in[B[i]] = false;
	X[A[i]] ^= X[B[i]];
	X[A[i]] ^= W[i];
    }

    UnionFind U(N);
    VI E;
    REP (i, M) if (A[i] != 0) {
	if (U.same(A[i], B[i])) {
	    E.push_back(i);
	} else {
	    G[A[i]].push_back(i);
	    G[B[i]].push_back(i);
	    U.link(A[i], B[i]);
	}
    }

    VI ord;
    REP (i, N) if (in[i]) {
	ord.clear();
	ord.push_back(i);
	depth[i] = 0;
	for (int j=0; j<(int)ord.size(); j++) {
	    int v = ord[j];
	    head[v] = i;
	    EACH (e, G[v]) {
		int w = v ^ A[*e] ^ B[*e];
		if (head[w] == 0) {
		    head[w] = i;
		    ord.push_back(w);
		    depth[w] = depth[v] ^ W[*e];
		}
	    }
	}
    }
    // rprintf("%d", depth, depth+N);

    EACH (e, E) {
	int h = head[A[*e]];
	int w = depth[A[*e]] ^ depth[B[*e]] ^ W[*e];
	if (!zero[h]) {
	    C[h] = push[C[h]][w];
	    if (C[h] == ~0u) zero[h] = true;
	}
	// if (!zero[h] && !C[h].push(w)) zero[h] = true;
    }

    Mint way = 1;
    cur[rnk[0]] = 1;
    REP (i, N) if (in[i] && !zero[i]) {
	if (!tri[i] && C[i] == 0u) { // non cycle;
	    way += way;
	    continue;
	}

	memset(nxt, 0, sizeof nxt);
	REP (z, value.size()) {
	    unsigned x = value[z];
	    Mint val = cur[z];
	    if (val.x == 0u) continue;
	    bool bad = false;
	    unsigned y;
	    y = C[i]&31;
	    if (y && !bad && (x = push[x][y]) == ~0u) bad = true;
	    y = C[i]>>5&15;
	    if (y && !bad && (x = push[x][y]) == ~0u) bad = true;
	    y = C[i]>>9&7;
	    if (y && !bad && (x = push[x][y]) == ~0u) bad = true;
	    y = C[i]>>12&3;
	    if (y && !bad && (x = push[x][y]) == ~0u) bad = true;
	    y = C[i]>>14&1;
	    if (y && !bad && (x = push[x][y]) == ~0u) bad = true;
	    if (!bad) {
		if (tri[i]) {
		    nxt[rnk[x]] += val + val;
		    if ((x = push[x][X[i]]) != ~0u) {
			nxt[rnk[x]] += val;
		    }
		} else {
		    nxt[rnk[x]] += val;
		}
	    }
	}
	REP (z, value.size()) cur[z] += nxt[z];
    }
    Mint ans = 0;
    REP (z, value.size()) ans += cur[z];
    ans *= way;
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}