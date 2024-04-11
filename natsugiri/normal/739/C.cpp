#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
struct Seg {
    LL l_val;
    int l_uplen, l_dnlen;
    LL r_val;
    int r_uplen, r_dnlen;
    int best_len;
    int len;
    Seg()  { best_len = l_val = r_val = -1; len = 0; }
    Seg(LL val_) {
	l_val = r_val = val_;
	l_uplen = l_dnlen = 
	    r_uplen = r_dnlen =
	    best_len = 1;
	len = 1;
    }
};

Seg operator*(const Seg &x, const Seg &y) {
    if (x.r_val == -1) return y;
    if (y.l_val == -1) return x;

    // TODO: do stuff something
    Seg z = Seg();
    z.l_val = x.l_val;
    z.r_val = y.r_val;

    z.l_uplen = x.l_uplen;
    z.l_dnlen = x.l_dnlen;
    z.r_uplen = y.r_uplen;
    z.r_dnlen = y.r_dnlen;
    z.best_len = max(x.best_len, y.best_len);
    z.len = x.len + y.len;

    if (x.r_val > y.l_val) {
	amax(z.best_len, x.r_dnlen + y.l_dnlen);
	amax(z.best_len, x.r_uplen + y.l_dnlen);
	if (x.r_uplen == x.len) amax(z.l_uplen, x.len + y.l_dnlen);
	if (x.r_dnlen == x.len) amax(z.l_uplen, x.len + y.l_dnlen);
	if (x.l_dnlen == x.len) amax(z.l_dnlen, x.len + y.l_dnlen);
	if (x.l_uplen == x.len) amax(z.l_uplen, x.len + y.l_dnlen);
	if (y.l_dnlen == y.len) {
	    amax(z.r_dnlen, x.r_dnlen + y.len);
	    amax(z.r_dnlen, x.r_uplen + y.len);
	}
    } 
    if (x.r_val < y.l_val) {
	amax(z.best_len, x.r_uplen + y.l_uplen);
	amax(z.best_len, x.r_uplen + y.l_dnlen);
	if (x.r_uplen == x.len) {
	    amax(z.l_uplen, x.len + y.l_uplen);
	    amax(z.l_uplen, x.len + y.l_dnlen);
	}
	if (y.l_uplen == y.len) amax(z.r_dnlen, x.r_uplen + y.len);
	if (y.l_dnlen == y.len) amax(z.r_dnlen, x.r_uplen + y.len);
	if (y.r_uplen == y.len) amax(z.r_uplen, x.r_uplen + y.len);
	if (y.r_dnlen == y.len) amax(z.r_dnlen, x.r_uplen + y.len);
    }

    amax(z.best_len, z.l_uplen);
    amax(z.best_len, z.l_dnlen);
    amax(z.best_len, z.r_uplen);
    amax(z.best_len, z.r_dnlen);
    return z;
};
const Seg unit = Seg();

struct Lazy {
    LL add;
    Lazy() : add(0) {}
    Lazy(LL val_) : add(val_) {}

    Lazy& operator+=(const Lazy &y) {
	// TODO: do stuff something
	add += y.add;
	return *this;
    }
};

const Lazy lazy_unit = Lazy();

Seg operator+(const Lazy &x, const Seg &y) {
    // TODO: do stuff something
    Seg z = y;
    if (z.l_val != -1) z.l_val += x.add;
    if (z.r_val != -1) z.r_val += x.add;
    return z;
}

struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	lazy.assign(m*2, lazy_unit);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, lazy_unit);
    }

    inline void force(int k) {
//	if (k < m) { // Lazy down
//	    lazy[k*2] += lazy[k];
//	    lazy[k*2+1] += lazy[k];
//	    // TODO: d[k] update with Lazy
//	    d[k] = eval(k*2) * eval(k*2+1);
//	    lazy[k] = lazy_unit;
//	}
    }

    inline Seg eval(int k) {
	return lazy[k] + d[k];
    }

    void add(int x, int y, LL v) { add(x, y, v, 1, 0, m); }

    void add(int x, int y, LL v, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k] += Lazy(v); return; } // TODO: Lazy update
	add(x, y, v, k*2, l, (l+r)/2); add(x, y, v, k*2+1, (l+r)/2, r); 
	d[k] = eval(k*2) * eval(k*2+1);
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return eval(k);
	return lazy[k] + query(x, y, k*2, l, (l+r)/2) * query(x, y, k*2+1, (l+r)/2, r);
    }
};

int N, Q;
int A[300111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    SegmentTree S(VI(A, A+N));
    scanf("%d", &Q);
    REP ($, Q) {
	int l, r, d;
	scanf("%d%d%d", &l, &r, &d);
	S.add(l-1, r, d);

	Seg s = S.query(0, N);
	printf("%d\n", s.best_len);
    }

    return 0;
}