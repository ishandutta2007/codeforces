#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
    RXQ(int n_, const T init=T()) : n(n_), m(ceil_pow2(n)), d(2*m, init) {}

    template<class Iter> void build(Iter begin, Iter end, const T init=T()) {
	n = end - begin;
	m = ceil_pow2(n);
	d.resize(2*m);
	for (int i=0; begin!=end; ++begin, i++) d[i+m] = *begin;
	for (int i=n; i<m; i++) d[i+m] = init;
	for (int i=m; --i; ) d[i] = max(d[i*2+1], d[i*2]);
    };

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

struct Seg {
    int val;
    Seg() : val(0) {}
    Seg(int val_): val(val_) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    z.val = min(x.val, y.val);
    return z;
};

struct Lazy {
    int add;
    Lazy() : add(0) {}
    Lazy(LL val_) : add(val_) {}

    Lazy& operator*=(const Lazy &y) {
	// TODO: do stuff something
	add += y.add;
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    // TODO: do stuff something
    Seg z;
    z.val = x.val + y.add;
    return z;
}

struct SegTreeLazy {
    int m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n=1) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    inline Seg eval(int k) {
	return d[k] * lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s * lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::IDENTITY;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) + eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::IDENTITY;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) + rs;
	    if (x & 1) ls = ls + eval(x++);
	}
	return ls + rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] *= v;
	    if (x0 & 1) lazy[x0++] *= v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) + eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) + eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    int find(int x) { return find(x, 1, 0, m); }

    int find(int x, int k, int l, int r) {
	force(k);
	if (r<=x) return -1;
	if (x<=l && eval(k).val > 0) return -1;
	if (r-l == 1) return l;

	int left = find(x, k*2, l, (l+r)/2);
	if (left != -1) return left;

	return find(x, k*2+1, (l+r)/2, r);
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::IDENTITY;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left + right;
    }
};

int N;
int P[300011];
int Q[300011];
int ans[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%d", Q+i), Q[i]--;
    RXQ<int> rxq; rxq.build(P, P+N);
    SegTreeLazy bk(N);

    REP (i, N) {
	ans[i] = rxq.max_v(0, N);

	int k = bk.find(Q[i]);
	if (k == -1) k = Q[i];
	int pos = rxq.max_i(0, k+1);
	rxq.modify(pos, -1);
	bk.add(pos, N, 1);
	bk.add(Q[i], N, -1);
    }
    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}