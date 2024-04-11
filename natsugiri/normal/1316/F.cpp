#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

const int MAX = 600011;
Mint POW2[MAX];
Mint POWINV2[MAX];

struct Seg {
    int len;
    Mint p, n;
    Mint sum;
    Seg(): len(0) {
	sum = 0;
    }
    Seg(Mint a) {
	len = 1;
	p = n = a;
	sum = 0;
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    Seg z;
    z.len = x.len + y.len;
    z.sum = x.sum + y.sum + x.p * y.n * POWINV2[x.len + 1];
    z.p = x.p + y.p * POW2[x.len];
    z.n = x.n + y.n * POWINV2[x.len];
    return z;
};

struct SegTree {
    int m; // m = 2^k >= n;
    vector<Seg> d;

    SegTree() {}

    SegTree(int n) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
    }

    template<class T> SegTree(const vector<T> &a) {
	int n = a.size();
        if (n < 2) m = 1;
        else m = 2 << __lg(n-1);
        d.assign(m*2, Seg::IDENTITY);
        REP (i, n) d[i+m] = Seg(a[i]);
        build();
    }

    template<class Iter> SegTree(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = Seg(*(begin+i));
	build();
    }

    // INIT := T initializer(int);
    template<class INIT> SegTree(int n, INIT initializer) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = initializer(i);
	build();
    }

    void build() {
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
    }

    Seg at(int x) const {
	return d[x+m];
    }

    void modify(int x, const Seg &s) {
	x += m;
	d[x] = s;
	for (x>>=1; x; x>>=1) d[x] = d[x*2] + d[x*2+1];
    }

    Seg query(int x, int y) const {
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (x+=m, y+=m; x<y; x>>=1, y>>=1) {
	    if (x&1) { ls = ls + d[x]; x++; }
	    if (y&1) { y--; rs = d[y] + rs; }
	}
	return ls + rs;
    }

    Seg query2(int x, int y) const { return query2(x, y, 1, 0, m); }

    Seg query2(int x, int y, int k, int l, int r) const {
	assert(x < r || l < y); // Has intersection;
	if (x<=l && r<=y) return d[k];
	int mid = (l+r)/2;
	if (y <= mid) return query2(x, y, k*2, l, mid);
	if (mid <= x) return query2(x, y, k*2+1, mid, r);
	return query2(x, y, k*2, l, mid) + query2(x, y, k*2+1, mid, r);
    }

    // VALID := bool valid(Seg);
    // find shortest valid range [l, ret);
    // otherwise ret = -1;
    template<class VALID> int find_first(int l, VALID valid) {
	if (valid(Seg::IDENTITY)) return l;
	Seg ls = Seg::IDENTITY, tmp;
	l += m;
	for (int r=m*2; l<r; l>>=1, r>>=1) {
	    if (l&1) {
		tmp = ls + d[l];
		if (valid(tmp)) {
		    while (l < m) {
			tmp = ls + d[l*2];
			if (valid(tmp)) l = l*2;
			else { ls = tmp; l = l*2+1; }
		    }
		    return l-m+1;
		}
		ls = tmp; l++;
	    }
	}
	return -1; // not found;
    }

    // VALID := bool valid(Seg);
    // find shortest valid range [ret, r);
    // otherwise ret = -1;
    template<class VALID> int find_last(int r, VALID valid) {
	if (valid(Seg::IDENTITY)) return r;
	Seg rs = Seg::IDENTITY, tmp;
	r += m;
	for (int l=m; l<r; l>>=1, r>>=1) {
	    if (r&1) {
		tmp = d[--r] + rs;
		if (valid(tmp)) {
		    while (r < m) {
			tmp = d[r*2+1] + rs;
			if (valid(tmp)) r = r*2+1;
			else { rs = tmp; r = r*2; }
		    }
		    return r-m;
		}
		rs = tmp;
	    }
	}
	return -1; // not found;
    }
};

int N, Q;
int A[300011];
int pos[300011], val[300011];
int idx[300011];

void MAIN() {
    POW2[0] = 1;
    POW2[1] = 2;
    POWINV2[0] = POW2[0];
    POWINV2[1] = 1 / POW2[1];
    for (int i=1; i<MAX; i++) {
	POW2[i+1] = POW2[i] * POW2[1];
	POWINV2[i+1] = POWINV2[i] * POWINV2[1];
    }

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &Q);
    REP (i, Q) {
	scanf("%d%d", pos+i, val+i);
	pos[i]--;
    }

    vector<pair<int, int> > vals;
    REP (i, N) vals.emplace_back(A[i], i);
    REP (i, Q) vals.emplace_back(val[i], i+N);
    sort(vals.begin(), vals.end());

    REP (i, vals.size()) if (vals[i].second < N) idx[vals[i].second] = i;

    auto init = [&](int i) {
	if (vals[i].second >= N) {
	    return Seg::IDENTITY;
	} else {
	    return Seg(vals[i].first);
	}
    };

    SegTree X(vals.size(), init);

    printf("%d\n", X.query(0, vals.size()).sum.geti());
    REP (i, Q) {
	int id = idx[pos[i]];
	X.modify(id, Seg::IDENTITY);
	int k = lower_bound(vals.begin(), vals.end(), make_pair(val[i], i+N)) - vals.begin();
	idx[pos[i]] = k;
	X.modify(k, Seg(val[i]));
	printf("%d\n", X.query(0, vals.size()).sum.geti());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}