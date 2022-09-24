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
template<class T> struct Fenwick {
    int n;
    T* d;
    Fenwick() : n(0), d(NULL) {}
    Fenwick(int n_) : n(n_) {
	d = new T[n_]();
    }
    Fenwick(const Fenwick &y) : n(y.n) {
	d = new T[n];
	memcpy(d, y.d, sizeof (T) * n);
    }
    ~Fenwick() {
	delete[] d; d = NULL;
	n = 0;
    }
    friend void swap(Fenwick &x, Fenwick &y) {
	swap(x.n, y.n); swap(x.d, y.d);
    }
    Fenwick& operator=(Fenwick y) {
	swap(*this, y);
	return *this;
    }
    inline void add(int i, const T &x) {
	for (; i<n; i|=i+1) d[i] += x;
    }
    inline T sum(int r) {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};

const int INF = 1<<29;
struct Seg {
    int val, pos;
    Seg() : val(INF), pos(0) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.val < y.val) return x;
    else return y;
};

struct Lazy {
    int add;
    Lazy() : add(0) {}
    Lazy(int val_) : add(val_) {}

    Lazy& operator*=(const Lazy &y) {
	add += y.add;
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    Seg z;
    z.val = x.val + y.add;
    z.pos = x.pos;
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
int N, Q;
int A[300011];
struct Query {
    int x, y, i;
    Query() {}
    Query(int x_, int y_, int i_): x(x_), y(y_), i(i_) {}

    bool operator<(const Query &o) const {
	return x < o.x;
    }
} query[300011];

int ans[300011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	query[i].x = x;
	query[i].y = y;
	query[i].i = i;
    }

    sort(query, query + Q);

    SegTreeLazy tree(N);
    Fenwick<int> F(N);

    int idx = N-1;

    for (int i_=Q; i_--;) {
	int x = query[i_].x;
	int y = query[i_].y;
	int qi = query[i_].i;

	while (x <= idx) {
	    if (A[idx] <= idx) {
		Seg update;
		update.val = idx - A[idx];
		update.pos = idx;
		tree.modify(idx, update);

		while (1) {
		    Seg seg = tree.query(idx, N);
		    if (seg.val <= 0) {
			tree.add(seg.pos, N, -1);
			update.val = INF;
			update.pos = seg.pos;
			tree.modify(seg.pos, update);
			F.add(seg.pos, 1);
		    } else {
			break;
		    }
		}
	    }

	    idx--;
	}

	ans[qi] = F.sum(x, N-y);
    }

    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}