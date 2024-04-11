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

//const LL MOD = 1000000007;
const LL MOD = 998244353;
typedef ModInt<MOD> Mint;

const int MAXN = 100011;
const int MAGIC = 200;
const int SIZE = (MAXN + MAGIC - 1) / MAGIC;

int N, K;
int A[100011];
int prv[100011], pprv[100011];

struct Data {
    int k, i;
    Mint m;

    Data() {
	k = 0;
	i = -1;
	m = 0;
    }

    bool operator<(const Data &d) const {
	return k < d.k;
    }
};

struct Block {
    int offset;
    Data D[MAGIC];
    Mint sums[MAGIC+1];
    int len;
    Mint ans;

    Block() {
	offset = 0;
	len = 0;
	ans = 0;
    }

    void add(int diff) {
	offset += diff;
	calc();
    }

    void calc() {
	Data key;
	key.k = K - offset;
	int pos = upper_bound(D, D+len, key) - D;
	ans = sums[pos];
    }

    void add(int L, int R, int diff) {
	REP (i, len) {
	    if (L <= D[i].i && D[i].i < R) {
		D[i].k += diff;
	    }
	}

	build();
    }

    void build() {
	sort(D, D+len);
	sums[0] = 0;
	REP (i, len) sums[i+1] = sums[i] + D[i].m;
	calc();
    }

    void ins(int i, Mint m) {
	D[len].i = i;
	D[len].m = m;
	D[len].k = -offset;
	len++;
	assert(len <= MAGIC);
    }

    Mint sum(int L, int R) {
	Mint ret = 0;
	REP (i, len) {
	    if (L <= D[i].i && D[i].i < R && D[i].k + offset <= K) {
		ret += D[i].m;
	    }
	}

	return ret;
    }

} B[SIZE];

void add(int L, int R, int diff) {
    R--;
    if (R < L) return;

    int bl = L / MAGIC, br = R / MAGIC;
    if (bl == br) {
	B[bl].add(L, R+1, diff);
    } else {
	for (int i=bl+1; i<br; i++) {
	    B[i].add(diff);
	}

	B[bl].add(L, R+1, diff);
	B[br].add(L, R+1, diff);
    }
}

Mint sum(int L, int R) {
    R--;
    assert(L <= R);

    int bl = L / MAGIC, br = R / MAGIC;
    Mint ret = 0;
    if (bl == br) {
	ret += B[bl].sum(L, R+1);
    } else {
	for (int i=bl+1; i<br; i++) {
	    ret += B[i].ans;
	}

	ret += B[bl].sum(L, R+1);
	ret += B[br].sum(L, R+1);
    }

    return ret;
}

void insert(int i, Mint m) {
    int b = i / MAGIC;
    B[b].ins(i, m);
    if (B[b].len == MAGIC) B[b].build();
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    insert(0, 1);
    REP (i, N) {
	int a = A[i];
	add(prv[a], i+1, +1);
	add(pprv[a], prv[a], -1);
	pprv[a] = prv[a];
	prv[a] = i+1;

	Mint m = sum(0, i+1);

	if (i == N-1) {
	    printf("%d\n", m.geti());
	    return;
	}
	insert(i+1, m);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}