#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    LL at_most;
    Lazy() : at_most(INF) {}
    //Lazy(LL a) : at_most(INF) {}
    Lazy(LL m) : at_most(m) {}

    friend Seg operator*(Seg x, const Lazy &y) {
	x.ma = min(y.at_most, x.ma);
	return x;
    }

    // seg + below + above --> seg + new_below;
    // above(below(seg));
    friend Lazy& operator*=(Lazy &below, const Lazy &above) {
	below.at_most = min(below.at_most, above.at_most);
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

int A[100011];
VI B[100011];
int idx[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int target = 1;
    REP (i, N) if (A[i] != 1) {
	target++;
	break;
    }
    if (target == 2) {
	REP (i, N) B[A[i]].push_back(i);
	REP (i, N+2) B[i].push_back(N);

	REP (i, N) idx[i] = i;
	SegTree tree(idx, idx+N);

	for (int t=1; ; t++) {
	    if (B[t][0]) {
		tree.apply(0, B[t][0], Lazy(-1));
	    }

	    REP (i, B[t].size()-1u) {
		tree.apply(B[t][i], B[t][i+1], Lazy(B[t][i]));
	    }

//	    eprintf("[%d] ", t);
//	    REP (i, N) eprintf("%d ", (int) tree.query(i, i+1).ma);
//	    eprintf("\n");

	    bool ok = false;

	    int left = 0;
	    REP (i, B[t+1].size()) {
		if (B[t+1][i]) {
		    Seg s = tree.query(B[t+1][i]-1, B[t+1][i]);
		    if (left <= s.ma) {
			ok = true;
			break;
		    }
		}
		left = B[t+1][i] + 1;
	    }

	    if (ok) {
		target++;
		continue;
	    } else {
		break;
	    }
	}
    }

    printf("%d\n", target);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}