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
    int val, all;
    Seg() : val(0), all(0) {}
    Seg(int val_) {
	val = val_;
	all = val_;
    }

    static const Seg unit;
};
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    Seg z;
    z.val = x.val + y.val;
    z.all = x.all + y.all;
    return z;
};

struct Lazy {
    int st;
    Lazy() : st(-1) {}
    Lazy(int st_) {
	st = st_;
    }

    Lazy& operator+=(const Lazy &y) {
	if (y.st != -1) {
	    st = y.st;
	}
	return *this;
    }

    static const Lazy unit;
};
const Lazy Lazy::unit = Lazy();

Seg operator+(const Seg &x, const Lazy &y) {
    Seg z = x;
    if (y.st == -1) {
    } else if (y.st == 0) {
	z.val = 0;
    } else {
	z.val = x.all;
    }
    return z;
}

struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	lazy.assign(m*2, Lazy::unit);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, Lazy::unit);
    }

    template<class Iter> SegmentTree(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, Lazy::unit);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    d[k] = eval(k*2) * eval(k*2+1);
	    lazy[k] = Lazy::unit;
	}
    }

    inline Seg eval(int k) {
	return d[k] + lazy[k];
    }

    void add(int x, int y, const Lazy &v) { add(x, y, v, 1, 0, m); }

    void add(int x, int y, const Lazy &v, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k] += v; return; }
	add(x, y, v, k*2, l, (l+r)/2); add(x, y, v, k*2+1, (l+r)/2, r); 
	d[k] = eval(k*2) * eval(k*2+1);
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	// if (r<=x || y<=l) return Seg::unit; // never use;
	if (x<=l && r<=y) return eval(k);
	int mid = (l+r)/2;
	if (y <= mid) return query(x, y, k*2, l, mid);
	if (mid <= x) return query(x, y, k*2+1, mid, r);
	return query(x, y, k*2, l, mid) * query(x, y, k*2+1, mid, r);
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::unit;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left * right;
    }
};
int N, Q;
int L[300111], R[300111], K[300111];
int Z[600111];

void MAIN() {
    scanf("%d%d", &N, &Q);
    VI P; P.reserve(2*Q + 2);
    REP (i, Q) {
	scanf("%d%d%d", L+i, R+i, K+i);
	L[i]--;
	P.push_back(L[i]);
	P.push_back(R[i]);
    }

    P.push_back(0);
    P.push_back(N);
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    int len = P.size() - 1;
    REP (i, P.size()-1) Z[i] = P[i+1] - P[i];

    SegmentTree X(Z, Z+len);

    REP (i, Q) {
	int li = lower_bound(P.begin(), P.end(), L[i]) - P.begin();
	int ri = lower_bound(P.begin(), P.end(), R[i]) - P.begin();
	if (K[i] == 1) {
	    X.add(li, ri, Lazy(0));
	} else {
	    X.add(li, ri, Lazy(1));
	}
	Seg s = X.query(0, N);
	printf("%d\n", s.val);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}