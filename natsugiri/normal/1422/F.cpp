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
template<class T> struct RXQ {
    static const int npos = -1;

    static int ceil_pow2(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return 2<<__lg(n-1);
    }

    int n, m;
    vector<T> d;
    RXQ() {}

    RXQ(int n_, const T init=T()) : n(n_), m(ceil_pow2(n)), d(2*m, init) {
	build_with_initializer([init](int i) { return init; });
    }

    template<class Iter> RXQ(Iter begin, Iter end, const T init=T()): n(end-begin), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer([&](int i) {
		if (i < n) return *(begin+i);
		else return init;
		});
    }

    template<class Initializer> RXQ(int n_, Initializer func): n(n_), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer(func);
    }

    template<class Initializer> inline void build_with_initializer(Initializer func) {
	// func(0) ... func(2^k-1);
	for (int i=0; i<m; i++) d[i+m] = func(i);
	for (int i=m; --i; ) d[i] = max(d[i*2+1], d[i*2]);
    }

    const T at(int i) const { return d[i+m]; }

    void modify(int i, const T v) {
	i += m; d[i] = v;
	for (i>>=1; i; i>>=1) d[i] = max(d[i*2+1], d[i*2]);
    }

    T max_v(int l, int r) const {
	l += m; r += m;
	T ret = d[l++];
	for (; l<r; l>>=1, r>>=1) {
	    if (l & 1) { amax(ret, d[l]); l++; }
	    if (r & 1) { r--; amax(ret, d[r]); }
	}
	return ret;
    }

    int max_i(int l, int r) const {
	return first_more_equal(l, max_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) > v: return i;
    // return npos;
    int first_more_than(int l, const T v) const {
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (v < d[l]) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (v < d[l*2]) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [l .. n-1]:
    //   if v <= at(i): return i;
    // return npos;
    int first_more_equal(int l, const T v) const { 
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (v <= d[l]) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (v <= d[l*2]) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [r-1 .. 0]:
    //   if v < at(i): return i;
    // return npos;
    int last_more_than(int r, const T v) const {
	if (r < m) {
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (v < d[r]) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (v < d[1]) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (v < d[r*2+1]) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }

    // for i in [r-1 .. 0]:
    //   if v <= at(i): return i;
    // return npos;
    int last_more_equal(int r, const T v) const { 
	if (r < m) { 
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (v <= d[r]) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (v <= d[1]) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (v <= d[r*2+1]) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }
};

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

const int MAX = 200011;
int min_factor[MAX];
vector<int>prime;
void make_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
}
int rnk[MAX];

const int MAXN = 100011;
const int MAGIC = 400;
int N, Q;
int A[MAXN];

const int SIZE = 20011;
VI index[SIZE];
int Left[MAXN], Right[MAXN];

int S[MAXN];

RXQ<int> rxq[90];

void add(int i, int p, int cnt) {
    if (p >= 450) {
	index[rnk[p]].push_back(i);
	S[i] = p;
    } else {
	// rnk[p] < 87;
	rxq[rnk[p]].modify(i, cnt);
    }
}

Mint B[MAXN/MAGIC+1][MAXN/MAGIC+1];

void build() {
    memset(Left, 0xc0, sizeof Left);
    memset(Right, 0x3f, sizeof Right);

    REP (i, SIZE) {
	REP (j, index[i].size()) {
	    if (j) Left[index[i][j]] = index[i][j-1];
	    if (j+1 < (int)index[i].size()) Right[index[i][j]] = index[i][j+1];
	}
    }

    for (int i=0; i<N; i+=MAGIC) {
	Mint val = 1;
	int l = i, r = i + MAGIC;
	while (r <= N) {
	    for (int k=l; k<r; k++) {
		int p = S[k];
		if (p == 0) continue;
		if (Left[k] < i) val *= p;
	    }

	    B[i/MAGIC][r/MAGIC] = val;
	    l = r;
	    r += MAGIC;
	}
    }
}


void MAIN() {
    make_prime();
    REP (i, prime.size()) rnk[prime[i]] = i;


    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, 87) rxq[i] = RXQ<int>(N, 0);

    REP (i, N) {
	int a = A[i];
	for (int p=2; p*p<=a; p++) {
	    int cnt = 0;
	    while (a % p == 0) {
		cnt++;
		a /= p;
	    }
	    
	    if (cnt) add(i, p, cnt);
	}
	if (a > 1) add(i, a, 1);
    }

    build();
    scanf("%d", &Q);
    LL last = 0;
    REP ($, Q) {
	LL x, y;
	scanf("%lld%lld", &x, &y);
	int l = (last + x) % N + 1;
	int r = (last + y) % N + 1;
	if (l > r) swap(l, r);


	l--;
	Mint ans = 1;
	REP (i, 87) {
	    int ma = rxq[i].max_v(l, r);
	    if (ma) {
		ans *= Mint(prime[i]).pow(ma);
	    }
	}

	int l2 = l, r2 = r;
	while (l2 % MAGIC != 0) l2++;
	while (r2 % MAGIC != 0) r2--;
	if (l2 < r2) {
	    ans *= B[l2/MAGIC][r2/MAGIC];
	} else {
	    l2 = r2 = l;
	}

	for (; r2<r; r2++) {
	    int p = S[r2];
	    if (p == 0) continue;
	    if (Left[r2] < l2) ans *= p;
	}
	while (1) {
	    l2--;
	    if (l2 < l) break;
	    int p = S[l2];
	    if (p == 0) continue;
	    if (r2 <= Right[l2]) ans *= p;
	}

	printf("%d\n", ans.geti());
	last = ans.geti();
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}