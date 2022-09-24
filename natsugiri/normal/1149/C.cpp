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
    int all;
    int lpos, lchange;
    int rneg, rchange;
    int best;
    int changing;

    Seg() {
	best = -1;
    }
    Seg(char c) {
	if (c == '(') {
	    all = 1;
	    lpos = 1;
	    rneg = 0;
	} else {
	    all = -1;
	    lpos = 0;
	    rneg = 1;
	}
	lchange = 1;
	rchange = 1;
	best = 1;
	changing = 1;
    }

    static const Seg unit;
};
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    if (x.best == -1) return y;
    if (y.best == -1) return x;
    Seg z;
    z.all = x.all + y.all;
    z.best = max(x.best, y.best);
    amax(z.best, x.rneg + y.lchange);
    amax(z.best, x.rchange + y.lpos);
    amax(z.best, x.rneg + y.lpos); // 

    z.lpos = max(x.lpos, x.all + y.lpos);
    z.lchange = x.lchange;
    amax(z.lchange, -x.all + y.lchange);
    amax(z.lchange, x.changing + y.lpos);

    z.rneg = max(x.rneg - y.all, y.rneg);
    z.rchange = y.rchange;
    amax(z.rchange, x.rchange + y.all);
    amax(z.rchange, x.rneg + y.changing);

    z.changing = abs(z.all);
    amax(z.changing, x.changing + y.all);
    amax(z.changing, -x.all + y.changing);
    amax(z.changing, -x.all + y.all);

//    eprintf("%d %d %d %d %d\n", x.all, x.rneg, x.rchange, x.lpos, x.lchange);
//    eprintf("%d %d %d %d %d\n", y.all, y.rneg, y.rchange, y.lpos, y.lchange);
//    eprintf("%d %d %d %d %d\n", z.all, z.rneg, z.rchange, z.lpos, z.lchange);
//    assert(z.rneg <= z.rchange);
//    assert(z.lpos <= z.lchange);

    return z;
};

struct SegmentTree {
    int n, m;
    vector<Seg> d;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
    }

    template<class Iter> SegmentTree(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
    }

    void modify(int x, const Seg &s) {
	x += m;
	d[x] = s;
	for (x>>=1; x; x>>=1) d[x] = d[x*2] * d[x*2+1];
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	// if (r<=x || y<=l) return Seg::unit; // never use;
	if (x<=l && r<=y) return d[k];
	int mid = (l+r)/2;
	if (y <= mid) return query(x, y, k*2, l, mid);
	if (mid <= x) return query(x, y, k*2+1, mid, r);
	return query(x, y, k*2, l, mid) * query(x, y, k*2+1, mid, r);
    }
};
int N, Q;
char S[400011];
int A[400011];
SegmentTree X;

int len;
void update(int k) {
    if (S[k] == '(') {
	X.modify(k, ')');
	S[k] = ')';
    } else {
	X.modify(k, '(');
	S[k] = '(';
    }
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", S);
    len = strlen(S);

    X = SegmentTree(S, S+len);

    REP ($, Q+1) {
	//puts(S);
	printf("%d\n", X.query(0, len).best);
	if ($ == Q) break;

	int a, b;
	scanf("%d%d", &a, &b);
	if (a != b) {
	    a--; b--;
	    update(a);
	    update(b);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}