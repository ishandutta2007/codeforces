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
    int l, r, len, best;
    Seg() { l = r = best = len = 0; }
    Seg(int val_) { 
	len = 1;
	l = r = best = val_;
    }
};

Seg operator*(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x; 
    // TODO: do stuff something
    Seg z;
    z.l = (x.l == x.len? x.len + y.l: x.l);
    z.r = (y.r == y.len? y.len + x.r: y.r);
    z.len = x.len + y.len;
    z.best = max(x.best, max(y.best, x.r + y.l));
    return z;
};
const Seg unit = Seg();
struct SegmentTree {
    int n;
    vector<Seg> d;
    SegmentTree(int n_=0): n(n_), d(2*n) { }
    SegmentTree(const vector<Seg> & d_): n(d_.size()), d(2*n) {
	for (int i=0; i<n; i++) d[i+n] = d_[i];
	for (int i=n; --i; ) d[i] = d[i*2] * d[i*2+1];
    }
    void reset() {
	REP (i, 2 * n) d[i] = Seg(0);
    }
    void modify(int i, const Seg &s) {
	i += n;
	d[i] = s;
	for (i/=2; i; i/=2) d[i] = d[i*2] * d[i*2+1];
    }
    Seg query(int x, int y) {
	x += n; y += n;
	Seg ls = unit, rs = unit;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = d[--y] * rs;
	    if (x & 1) ls = ls * d[x++];
	}
	return ls * rs;
    }
};


int N, Q;
pair<int, int> H[100111];
struct Query {
    int l, r, w;
    int d;
    int id;
    bool operator<(const Query &y) const {
	return y.d < d;
    }
} query[100111];

int ans[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", &H[i].first), H[i].second = i;
    sort(H, H+N, greater<pair<int, int> >());
    scanf("%d", &Q);
    REP (i, Q) {
	scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].w);
	query[i].l--;
	query[i].d = 0;
	query[i].id = i;
    }

    SegmentTree X(N);
    for (int diff = 1<<29; diff; diff >>= 1) {
	sort(query, query + Q);
	X.reset();

	int cur = 0;
	REP (i, Q) {
	    while (cur < N && H[cur].first >= query[i].d + diff) {
		X.modify(H[cur].second, 1);
		cur++;
	    }

	    Seg s = X.query(query[i].l, query[i].r);
	    if (s.best >= query[i].w) query[i].d += diff;
	}
    }

    REP (i, Q) ans[query[i].id] = query[i].d;
    REP (i, Q) printf("%d\n", ans[i]);

    return 0;
}