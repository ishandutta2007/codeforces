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

const int INF = 1<<29;
struct Seg {
    int val[15];
    Seg() { init(); }
    Seg(int v) {
	init();
	if (v == 2) {
	    val[0] = 1;
	    val[1] = 0;
	} else if (v == 0) {
	    val[2] = 1;
	    val[4] = 0;
	} else if (v == 1) {
	    val[5] = 1;
	    val[8] = 0;
	} else if (v == 7) {
	    val[9] = 1;
	    val[13] = 0;
	} else if (v == 6) {
	    val[9] = 1;
	    val[14] = 1;
	}
    }
    void init() {
	REP (i, 15) val[i] = INF;
	int s = 0;
	REP (i, 5) {
	    val[s] = 0;
	    s += i + 2;
	}
    }

    // assert (c <= r)
    int& get(int r, int c) {
	return val[r * (r+1)/2 + c];
    }
    const int& get(int r, int c) const {
	return val[r * (r+1)/2 + c];
    }
};

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    REP (i, 15) z.val[i] = INF;
    REP (i, 5) REP (k, i+1) REP (j, k+1) amin(z.get(i, j), y.get(i, k) + x.get(k, j));
    return z;
};
const Seg unit = Seg();

// Small Space
struct SegmentTree {
    int n;
    vector<Seg> d;
    SegmentTree(int n_=0): n(n_), d(2*n) { }
    SegmentTree(const vector<int> & d_): n(d_.size()), d(2*n, unit) {
	for (int i=0; i<n; i++) d[i+n] = d_[i];
	for (int i=n; --i; ) d[i] = d[i*2] * d[i*2+1];
    }
//    SegmentTree(const vector<Seg> & d_): n(d_.size()), d(2*n) {
//	for (int i=0; i<n; i++) d[i+n] = d_[i];
//	for (int i=n; --i; ) d[i] = d[i*2] * d[i*2+1];
//    }
//    void modify(int i, const Seg &s) {
//	i += n;
//	d[i] = s;
//	for (i/=2; i; i/=2) d[i] = d[i*2] * d[i*2+1];
//    }
    Seg query(int x, int y) {
	x += n; y += n;
	Seg ls = Seg(), rs = Seg();
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = d[--y] * rs;
	    if (x & 1) ls = ls * d[x++];
	}
	return ls * rs;
    }
};

int N, Q;
char S[200111];
int A[200111];

int main() {
    scanf("%d%d", &N, &Q);
    scanf("%s", S);
    REP (i, N) A[i] = S[i] - '0';
    SegmentTree X(VI(A, A+N));

    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	Seg s = X.query(l, r);

	if (s.val[10] >= INF) puts("-1");
	else printf("%d\n", s.val[10]);
    }

    return 0;
}