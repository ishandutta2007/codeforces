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

int X;

struct Seg {
    LL cnt;
    vector<pair<int, int> > L, R; // (val, len);
    Seg() {
	cnt = -1;
    }
    Seg(int val) {
	cnt = (X <= val? 1: 0);
	L.emplace_back(val, 1);
	R.emplace_back(val, 1);
    }

    static const Seg unit;
};
const Seg Seg::unit = Seg();

Seg operator*(const Seg &x, const Seg &y) {
    if (x.cnt == -1) return y;
    if (y.cnt == -1) return x;
    // TODO: do stuff something
    Seg z;
    z.cnt = x.cnt + y.cnt;

    LL len = 0;
    int j = (int)y.L.size() - 1;
    REP (i, x.R.size()) {
	while (j>=0 && X <= (x.R[i].first | y.L[j].first)) {
	    len += y.L[j].second;
	    j--;
	}
	z.cnt += x.R[i].second * len;
    }
    z.L = x.L;
    REP (i, y.L.size()) {
	int tmp = z.L.back().first | y.L[i].first;
	if (z.L.back().first == tmp) z.L.back().second += y.L[i].second;
	else z.L.emplace_back(tmp, y.L[i].second);
    }
    z.R = y.R;
    REP (i, x.R.size()) {
	int tmp = z.R.back().first | x.R[i].first;
	if (z.R.back().first == tmp) z.R.back().second += x.R[i].second;
	else z.R.emplace_back(tmp, x.R[i].second);
    }
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

    template<class Iter> SegmentTree(Iter begin, Iter end) {
	n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::unit);
	REP (i, n) d[i+m] = Seg(*(begin+i));
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

int N, M;
int A[100011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &X);
    REP (i, N) scanf("%d", A+i);

    SegmentTree S(A, A+N);
    REP ($, M) {
	int op, l, r;
	scanf("%d%d%d", &op, &l, &r);
	l--;
	if (op == 1) {
	    S.modify(l, Seg(r));
	} else {
	    Seg s = S.query(l, r);
	    printf("%lld\n", s.cnt);
	}
    }


}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}