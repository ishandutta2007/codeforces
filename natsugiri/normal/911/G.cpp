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
    int v;
    Seg() {
	v = 0;
    }
    Seg(int v_) {
	v = v_;
    }

    static const Seg unit;
};
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    return x;
};

struct Lazy {
    char mp[101];
    Lazy() {
	REP (i, 101) mp[i] = i;
	mp[0] = -1;
    }
    Lazy(int x, int y) {
	REP (i, 101) mp[i] = i;
	mp[x] = y;
    }

    Lazy& operator+=(const Lazy &y) {
	if (y.mp[0] == -1) return *this;
	// TODO: do stuff something
	Lazy z;	
	mp[0] = 0;
	REP (i, 101) mp[i] = y.mp[mp[i]];
	return *this;
    }

    static const Lazy unit;
};
const Lazy Lazy::unit = Lazy();

Seg operator+(const Seg &x, const Lazy &y) {
    // TODO: do stuff something
    return Seg(y.mp[x.v]);
}

// With Lazy
Seg d[1<<19];
Lazy lazy[1<<19];
struct SegmentTree {
    int n, m;
//    vector<Seg> d;
//    vector<Lazy> lazy;

//    SegmentTree(int n_=1) : n(n_) {
//	if (n < 2) m = 1;
//	else m = 2 << __lg(n-1);
//	d.assign(m*2, Seg::unit);
//	lazy.assign(m*2, Lazy::unit);
//    }

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
	//d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = *(begin+i);
	//for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	//lazy.assign(m*2, Lazy::unit);
    }

    inline void force(int k) {
	if (k < m && lazy[k].mp[0] != -1) { // Lazy down
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    //d[k] = eval(k*2) * eval(k*2+1);
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
	//d[k] = eval(k*2) * eval(k*2+1);
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

//    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }
//
//    Seg query_template(int x, int y, int k, int l, int r) {
//	force(k);
//	if (r<=x || y<=l) return Seg::unit;
//	if (x<=l && r<=y) return eval(k);
//	Seg left = query_template(x, y, k*2, l, (l+r)/2);
//	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
//	return left * right;
//    }
};

int N, Q;
int A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

#ifdef LOCAL
    N = 200000;
    REP (i, N) A[i] = rand() % 100 + 1;
#endif
    SegmentTree S(A, A+N);

    scanf("%d", &Q);

#ifdef LOCAL
    Q = 200000;
#endif

    REP ($, Q) {
	int l, r, x, y;

#ifdef LOCAL
	l = rand() % N;
	r = rand() % N;
	if (r > l) swap(l, r);
	l++; r++;
	l = 2; r = (1<<17)-1;
	x = rand() % 100 + 1;
	y = rand() % 100 + 1;
#else 
	scanf("%d%d%d%d", &l, &r, &x, &y);
#endif

	l--;
	S.add(l, r, Lazy(x, y));
    }

    REP (i, N) A[i] = S.query(i, i+1).v;
    rprintf("%d", A, A+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}