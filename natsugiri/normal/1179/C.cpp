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
struct Seg {
    int val;
    Seg() : val(0) {}
    Seg(int val_): val(val_) {}

    static const Seg UNIT;
};
const Seg Seg::UNIT = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z(max(x.val, y.val));
    return z;
};

struct Lazy {
    int add;
    Lazy() : add(0) {}
    Lazy(int val_) : add(val_) {}

    Lazy& operator+=(const Lazy &y) {
	// TODO: do stuff something
	add += y.add;
	return *this;
    }

    static const Lazy UNIT;
};
const Lazy Lazy::UNIT = Lazy();

Seg operator+(const Seg &x, const Lazy &y) {
    // TODO: do stuff something
    Seg z;
    z.val = x.val + y.add;
    return z;
}

struct SegTreeLazy {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::UNIT);
	lazy.assign(m*2, Lazy::UNIT);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::UNIT);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
	lazy.assign(m*2, Lazy::UNIT);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    d[k] = eval(k*2) * eval(k*2+1);
	    lazy[k] = Lazy::UNIT;
	}
    }

    inline Seg eval(int k) {
	return d[k] + lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s + lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::UNIT;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) * eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::UNIT;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::UNIT, rs = Seg::UNIT;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) * rs;
	    if (x & 1) ls = ls * eval(x++);
	}
	return ls * rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] += v;
	    if (x0 & 1) lazy[x0++] += v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) * eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) * eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    d[k] = eval(k*2) * eval(k*2+1);
	    lazy[k] = Lazy::UNIT;
	}
    }

    int find() {
	int k = 1, l = 0, r = m;
	if (eval(1).val <= 0) return -1;
	while (1) {
	    force(k);
	    if (l+1 == r) return l;
	    if (eval(k*2+1).val > 0) {
		k = k*2+1;
		l = (l+r)/2;
	    } else {
		k = k*2;
		r = (l+r)/2;
	    }
	}
    }
//    int find(int x, int y) { return find(x, y, 1, 0, m); }
//
//    int find(int x, int y, int k, int l, int r) {
//	force(k);
//	if (r<=x || y<=l) return -1;
//	if (eval(k).val <= 0) return -1;
//	if (l+1 == r) return l;
//
//	int ret = find(x, y, k*2+1, (l+r)/2, r);
//	if (ret == -1) ret = find(x, y, k*2, l, (l+r)/2);
//	return ret;
//    }
};

int N, M, Q;
int A[300011];
int B[300011];
const int SIZE = 1<<20;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);

    SegTreeLazy S(SIZE);
    REP (i, N) S.add(0, A[i]+1, 1);
    REP (i, M) S.add(0, B[i]+1, -1);

    scanf("%d", &Q);
    REP ($, Q) {
	char op[9];
	int i, x;
	scanf("%s%d%d", op, &i, &x);
	i--;
	if (*op == '1') {
	    S.add(0, A[i]+1, -1);
	    A[i] = x;
	    S.add(0, A[i]+1, 1);
	} else {
	    S.add(0, B[i]+1, 1);
	    B[i] = x;
	    S.add(0, B[i]+1, -1);
	}

	printf("%d\n", S.find());
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}