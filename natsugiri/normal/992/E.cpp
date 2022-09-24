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


const LL INF = 1LL<<60;
struct Seg {
    int i;
    LL val;
    Seg() : val(-INF) {
	i = -1;
    }
    Seg(LL val_): val(val_) {
	i = -1;
    }

    static const Seg unit;
};
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    if (x.val > y.val) return x;
    else return y;
};

struct Lazy {
    LL add;
    Lazy() : add(0) {}
    Lazy(LL val_) : add(val_) {}

    Lazy& operator+=(const Lazy &y) {
	// TODO: do stuff something
	add += y.add;
	return *this;
    }

    static const Lazy unit;
};
const Lazy Lazy::unit = Lazy();

Seg operator+(const Seg &x, const Lazy &y) {
    // TODO: do stuff something
    Seg z;
    z.val = x.val + y.add;
    z.i = x.i;
    return z;
}

// With Lazy
struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

//    SegmentTree(int n_=1) : n(n_) {
//	if (n < 2) m = 1;
//	else m = 2 << __lg(n-1);
//	d.assign(m*2, Seg::unit);
//	lazy.assign(m*2, Lazy::unit);
//    }
//
//    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
//	if (n < 2) m = 1;
//	else m = 2 << __lg(n-1);
//	d.assign(m*2, Seg::unit);
//	REP (i, n) d[i+m] = Seg(a[i]);
//	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
//	lazy.assign(m*2, Lazy::unit);
//    }

    template<class Iter> SegmentTree(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) {
	    d[i+m].val = *(begin+i);
	    d[i+m].i = i;
	}
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, Lazy::unit);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    d[k] = eval(k*2) * eval(k*2+1);
	    lazy[k] = Lazy::unit;
	} else {
	    d[k] = d[k] + lazy[k];
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

    Seg solve(int x, int y) { return solve(x, y, 1, 0, m); }

    Seg solve(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::unit;
	if (d[k].val == 0) return d[k];
	if (d[k].val < 0) return Seg::unit;
	if (l+1 >= r) return Seg::unit;
	Seg right = solve(x, y, k*2+1, (l+r)/2, r);
	if (right.val == 0) return right;
	Seg left = solve(x, y, k*2, l, (l+r)/2);
	return left;
    }
};

int N, Q;
int A[200011];
LL sums[200011];
LL B[200011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) sums[i+1] = sums[i] + A[i];

    REP (i, N) B[i] = A[i] - sums[i];
    SegmentTree X(B, B+N);

    REP ($, Q) {
	int pos, val;
	scanf("%d%d", &pos, &val);
	pos--;
	int diff = val - A[pos];
	A[pos] = val;

	if (pos + 1 < N) X.add(pos+1, N, -diff);
	X.add(pos, pos+1, diff);
//	REP (i, N) {
//	    Seg s = X.query(i, i+1);
//	    eprintf("[%lld %d]", s.val, s.i);
//	}
//	eprintf("\n");
	Seg ans = X.solve(0, N);
//	eprintf("%lld %d\n", ans.val, ans.i);
	if (ans.i <= -1) {
	    puts("-1");
	} else {
	    printf("%d\n", ans.i+1);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}