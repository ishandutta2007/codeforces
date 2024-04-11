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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

// Alternative Series
struct Seg {
    LL alt_sum; // alt sum in the segment, the last element is positive
    LL min_even; // minimum of alt_sum of even length (maybe 0) prefix. the last element is positive
    LL min_odd; // minimum of alt_sum of odd length prefix. the last element is negative
    int len; // length of the segment

    Seg() : alt_sum(0), min_even(1LL<<60), min_odd(1LL<<60), len(0) {} // empty
    Seg(LL v) : alt_sum(v), min_even(0), min_odd(v), len(1) {} // singleton
};

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.len = x.len + y.len;
    z.alt_sum = (y.len & 1 ? -x.alt_sum : x.alt_sum) + y.alt_sum;
    if (x.len & 1) {
	z.min_even = min(x.min_even, -x.alt_sum + y.min_odd);
	z.min_odd = min(x.min_odd, x.alt_sum + y.min_even);
    } else {
	z.min_even = min(x.min_even, x.alt_sum + y.min_even);
	z.min_odd = min(x.min_odd, -x.alt_sum + y.min_odd);
    }
    return z;
};

Seg unit = Seg();

struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<LL> lazy;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg());
	lazy.assign(m*2, 0);
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg());
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, 0);
    }

    void force(int k) {
	if (k < m) {
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	}
	if (d[k].len & 1) d[k].alt_sum += lazy[k];
	d[k].min_odd += lazy[k];
	lazy[k] = 0;
    }

    void add(int x, int y, LL v) { add(x, y, v, 1, 0, m); }

    void add(int x, int y, LL v, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k] += v; force(k); return; }
	add(x, y, v, k*2, l, (l+r)/2); add(x, y, v, k*2+1, (l+r)/2, r); 
	d[k] = d[k*2] + d[k*2+1];
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return d[k];
	return query(x, y, k*2, l, (l+r)/2) + query(x, y, k*2+1, (l+r)/2, r);
    }
};


int N, Q;
int A[200111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &Q);

    SegmentTree X(VI(A, A+N));

    REP ($, Q) {
	char op[9];
	int a, b, k;
	scanf("%s", op);
	scanf("%d%d", &a, &b);
	b++;

	if (op[0] == '1') {
	    scanf("%d", &k);
	    X.add(a, b, k);
	} else if (op[0] == '2') {
	    Seg s = X.query(a, b);
	    bool yes = false;
	    if (s.min_odd >= 1 && s.min_even >= 0) {
		if (s.alt_sum == 0 && s.len % 2 == 0) yes = true;
		if (s.alt_sum == 1 && s.len % 2 == 1) yes = true;
	    }

	    puts(yes? "1": "0");
	} else {


	}
    }

    return 0;
}