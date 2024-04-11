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

#include<random>
#include<chrono>
#include<memory>

uint64_t murmurhash3mixer(uint64_t x) {
    x ^= (x >> 33);
    x *= 0xff51afd7ed558ccdULL;
    x ^= (x >> 33);
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= (x >> 33);
    return x;
}

seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get(),
	murmurhash3mixer(random_device()()),
};

mt19937_64 engine(seq);
// for 32 bit env;
// mt19937 engine(seq);
namespace ROLLING_HASH {

typedef unsigned long long ULL;
const int PARALLEL = 2; // 1 or 2;
typedef array<ULL, PARALLEL> Hash;
const ULL MOD = (1ULL<<61)-1;
const int LEN = 1e7 + 11;

Hash POW[LEN];

// MOD operations;
Hash operator+(Hash x, const Hash &y) {
    REP (t, PARALLEL) if ((x[t] += y[t]) >= MOD) x[t] -= MOD;
    return x;
}
Hash operator-(Hash x, const Hash &y) {
    REP (t, PARALLEL) if ((x[t] += MOD-y[t]) >= MOD) x[t] -= MOD;
    return x;
}
ULL mul(ULL x, ULL y) {
    const ULL MASK31 = (1ULL<<31)-1;
    const ULL MASK30 = (1ULL<<30)-1;
    const ULL xh = x>>31;
    const ULL xl = x&MASK31;
    const ULL yh = y>>31;
    const ULL yl = y&MASK31;
    const ULL c = xl*yh + xh*yl;
    const ULL ch = c>>30;
    const ULL cl = c&MASK30;
    ULL z = xh*yh*2U + ch + (cl<<31) + xl*yl;
    z = (z>>61) + (z&MOD);
    return z<MOD? z: z-MOD;
}
Hash operator*(Hash x, const Hash &y) {
    REP (t, PARALLEL) x[t] = mul(x[t], y[t]);
    return x;
}
// MOD operations;

// Hash operations;
Hash zero() {
    static Hash h = {};
    return h;
}

Hash one(ULL x) {
    if (MOD <= x) x %= MOD;
    Hash h;
    REP (t, PARALLEL) h[t] = x;
    return h;
}

// push 0, n times;
Hash shift(Hash x, ULL n) {
    if (n < LEN) return x * POW[n];
    Hash y = POW[1];
    for (; n; n>>=1) {
	if (n & 1) x = x * y;
	y = y * y;
    }
    return x;
}

Hash push(Hash x, ULL y) {
    x = shift(x, 1);
    if (MOD <= y) y %= MOD;
    REP (t, PARALLEL) if ((x[t] += y) >= MOD) x[t] -= MOD;
    return x;
}

Hash concat(Hash x, Hash y, ULL ylen) {
    return shift(x, ylen) + y;
}

template<class Iter> Hash eval(Iter begin, Iter end) {
    Hash h = {};
    while (begin != end) h = push(h, *(begin++));
    return h;
}

Hash eval(const string &s) {
    return eval(s.begin(), s.end());
}

Hash repeate(Hash x, ULL xlen, ULL y) {
    if (xlen == 0) return x;
    Hash r = zero();
    Hash s = shift(POW[1], xlen);
    for (; y; y>>=1) {
	if (y&1) r = r * s + x;
	x = x * s + x;
	s = s * s;
    }
    return r;
}
// Hash operations;

struct _Init {
    _Init() {
	REP (t, PARALLEL) {
	    POW[0][t] = 1;
	    while (1) {
		POW[1][t] = engine() & MOD;
		if (1 < POW[1][t] && POW[1][t] < MOD-1) break;
	    }
	}
	for (int i=2; i<LEN; i++) POW[i] = shift(POW[i-1], 1);
    }
} _init;

struct RollingHash {
    vector<Hash> h;

    RollingHash() : h(1, Hash()) {}

    template<class Iter> RollingHash(Iter begin, Iter end) : h(end - begin + 1u) {
	h[0] = Hash();
	int i = 0;
	while (begin != end) {
	    assert(*begin > 0);
	    h[i+1] = push(h[i], *begin);
	    i++;
	    begin++;
	}
    }

    RollingHash(const string &s) : RollingHash(s.begin(), s.end()) {}

    void push_back(ULL c) {
	assert(c > 0);
	h.push_back(push(h.back(), c));
    }

    void pop_back() {
	h.pop_back();
    }

    Hash get(int l, int r) const {
	return h[r] - shift(h[l], r-l);
    }
};

}; // namespace RollingHash;
using namespace ROLLING_HASH;

struct Seg {
    int len;
    int c0;
    int head, tail;
    Hash h;
    Seg(): len(0), c0(0), head(0), tail(0), h(zero()) {}
    Seg(char c) {
	len = 1;
	if (c == '0') {
	    c0 = 1;
	    head = tail = 0;
	    h = POW[1];
	} else {
	    c0 = 0;
	    head = tail = 1;
	    h = zero();
	}
    }

    void normal() {
	if (c0) {
	    int in = tail / 2;
	    if (in) {
		tail &= 1;
		head += in*2;
		h = shift(h, in*2);
	    }
	}
    }


    bool operator==(const Seg &o) const {
	return c0 == o.c0 && head == o.head && tail == o.tail && h == o.h;
    }
    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;

    Seg z;
    z.len = x.len + y.len;

    if (x.c0 == 0 && y.c0 == 0) {
	z.c0 = 0;
	z.head = z.tail = z.len;
	z.h = zero();
    } else if (x.c0 == 0) {
	z.c0 = y.c0;
	z.head = x.head + y.head;
	z.tail = y.tail;
	z.h = shift(y.h, x.head);
    } else if (y.c0 == 0) {
	z.c0 = x.c0;
	z.head = x.head;
	z.tail = x.tail + y.tail;
	z.h = x.h;
    } else {
	int in = (x.tail + y.head) / 2;
	z.c0 = x.c0 + y.c0;
	z.head = x.head + in*2;
	z.tail = y.tail;
	z.h = shift(x.h, in*2) + shift(y.h, x.len);
    }
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

int N;
char S[200011];
int sums[200011];
int Q;

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    REP (i, N) sums[i+1] = sums[i] + (S[i] == '1'? 1: 0);
    
    scanf("%d", &Q);
    SegTree X(S, S+N);
    REP ($, Q) {
	int a, b, len;
	scanf("%d%d%d", &a, &b, &len);
	a--; b--;
	bool yes;
	if (sums[a+len] - sums[a] != sums[b+len] - sums[b]) {
	    yes = false;
	} else {
	    Seg sa = X.query(a, a+len);
	    Seg sb = X.query(b, b+len);
	    sa.normal();
	    sb.normal();
	    // eprintf("%d %d %d %llu %llu\n", sa.c0, sa.head, sa.tail, sa.h[0], sa.h[1]);
	    // eprintf("%d %d %d %llu %llu\n", sb.c0, sb.head, sb.tail, sb.h[0], sb.h[1]);
	    yes = (sa == sb);
	}
	puts(yes? "YES": "NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}