#include<deque>
#include<cassert>
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
    int val;
    int left, right;
    Seg() : val(0) {
	left = 0;
	right = 0;
    }
    Seg(int i) {
	val = 0;
	left = 0;
	right = 0;
	if (i == 0) left = 1;
	else right = 1;
    }
};

Seg operator*(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    z.val = x.val + y.val;
    int g = min(x.left, y.right);
    z.val += g;
    z.left = x.left + y.left - g;
    z.right = x.right + y.right - g;
    return z;
};
const Seg unit = Seg();

struct SegmentTree {
    int n, m;
    vector<Seg> d;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] * d[i*2+1];
    }

    void modify(int x, const Seg &s) {
	x += m;
	d[x] = s;
	for (x>>=1; x; x>>=1) d[x] = d[x*2] * d[x*2+1];
    }

//    void add(int x, int y, LL v) { add(x, y, v, 1, 0, m); }
//
//    void add(int x, int y, LL v, int k, int l, int r) {
//	if (r<=x || y<=l) return;
//	if (x<=l && r<=y) { d[k] += v; return; } // TODO: Seg update
//	add(x, y, v, k*2, l, (l+r)/2); add(x, y, v, k*2+1, (l+r)/2, r); 
//	d[k] = d[k*2] * d[k*2+1];
//    }
//
    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return d[k];
	return query(x, y, k*2, l, (l+r)/2) * query(x, y, k*2+1, (l+r)/2, r);
    }
};


int N;
int A[300111];
pair<int, int> P[300111];

int M[300111];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    memset(M, -1, sizeof M);

    LL ans = 0;

    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);

    SegmentTree S(N);
    REP (i, N) S.modify(i, Seg(1));
    REP (i, N) {
	int j = i;
	while (j < N && P[i].first == P[j].first) {
	    int v = P[j].second;
	    S.modify(v, Seg(0));
	    j++;
	}

	if (j < N) {
	    ans += (LL) S.query(0, N).val * (P[j].first - P[i].first);
	}

	i = j-1;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}