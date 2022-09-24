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
const LL INF = 1LL<<60;
struct Seg {
    LL ma; // minimum / maximum range query;
    Seg() : ma(-INF) {}
    Seg(LL val) : ma(val) {}
    friend Seg operator+(Seg x, const Seg &y) {
	amax(x.ma, y.ma);
	return x;
    }
};
const Seg unit = Seg();

struct Lazy {
    LL add, at_least;
    Lazy() : add(0), at_least(-INF) {}
    Lazy(LL a) : add(a), at_least(-INF) {}
    // l <= (val + a) <= m
    Lazy(LL a, LL l) : add(a), at_least(l) {}

    friend Seg operator*(Seg x, const Lazy &y) {
	x.ma = max(y.at_least, x.ma + y.add);
	return x;
    }

    // seg + below + above --> seg + new_below;
    // above(below(seg));
    friend Lazy& operator*=(Lazy &below, const Lazy &above) {
	below.add = max(-INF, min(INF, below.add + above.add));
	below.at_least = max(below.at_least + above.add, above.at_least);
	return below;
    }

    friend Lazy operator*(Lazy first, const Lazy &second) {
	return first *= second;
    }
};
const Lazy lazy_unit = Lazy();

struct SegTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTree(int n_=1) : n(n_), m(2<<__lg(max(1, n_))), d(m*2, unit), lazy(m*2, lazy_unit) { }

    template<class Iter> SegTree(Iter begin, Iter end) : n(end - begin), m(2<<__lg(max(1, n))), d(m*2, unit), lazy(m*2, lazy_unit) {
	REP (i, n) { d[i+m] = Seg(*begin); ++begin; }
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = lazy_unit;
	}
    }

    inline Seg eval(int k) const {
	return d[k] * lazy[k];
    }

    void apply(int x, int y, const Lazy &v) { apply(x, y, v, 1, 0, m); }

    void apply(int x, int y, const Lazy &v, int k, int l, int r) {
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k] *= v; return; }
	force(k);
	apply(x, y, v, k*2, l, (l+r)/2); apply(x, y, v, k*2+1, (l+r)/2, r);
	d[k] = eval(k*2) + eval(k*2+1);
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return eval(k);
	force(k);
	return query(x, y, k*2, l, (l+r)/2) + query(x, y, k*2+1, (l+r)/2, r);
    }
};


int N;

struct Data {
    int l, r, t;

    bool operator<(const Data &o) const {
	return l < o.l;
    }
} D[200011];

VI RS;

void MAIN() {
    scanf("%d", &N);
    RS.push_back(0);
    REP (i, N) {
	scanf("%d%d%d", &D[i].l, &D[i].r, &D[i].t);
	RS.push_back(D[i].r);
    }
    sort(D, D+N);

    sort(RS.begin(), RS.end());
    RS.erase(unique(RS.begin(), RS.end()), RS.end());

    SegTree R(RS.size()), B(RS.size());
    R.apply(0, 1, Lazy(0, 0));
    B.apply(0, 1, Lazy(0, 0));

    REP (i, N) {
	int left = lower_bound(RS.begin(), RS.end(), D[i].l) - RS.begin();
	int pos = lower_bound(RS.begin(), RS.end(), D[i].r) - RS.begin();

	if (D[i].t == 1) {
	    Seg seg = B.query(0, left);
	    // R.apply(pos, RS.size(), Lazy(1));
	    R.apply(pos, RS.size(), Lazy(1, seg.ma + 1));
	} else {
	    Seg seg = R.query(0, left);
	    // B.apply(pos, RS.size(), Lazy(1));
	    B.apply(pos, RS.size(), Lazy(1, seg.ma + 1));
	}
    }

    LL ans = max(R.query(0, RS.size()).ma, B.query(0, RS.size()).ma);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}