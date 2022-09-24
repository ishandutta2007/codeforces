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



template<class T> struct RMQ {
    static const int npos = -1;

    int n, m;
    vector<T> d;
    RMQ() {}
    RMQ(int n_, const T init=T()) : n(n_), m(2<<__lg(max(1, n))), d(2*m, init) {}
    template<class Iter> void build(Iter begin, Iter end, const T init=T()) {
	n = end - begin;
	m = 2<<__lg(max(1, n));
	d.resize(2*m);
	for (int i=0; begin!=end; ++begin, i++) d[i+m] = *begin;
	for (int i=n; i<m; i++) d[i+m] = init;
	for (int i=m; --i; ) d[i] = min(d[i*2+1], d[i*2]);
    };

    const T at(int i) const { return d[i+m]; }

    void modify(int i, const T v) {
	i += m; d[i] = v;
	for (i>>=1; i; i>>=1) d[i] = min(d[i*2+1], d[i*2]);
    }

    T min_v(int l, int r) const {
	l += m; r += m;
	T ret = d[l++];
	for (; l<r; l>>=1, r>>=1) {
	    if (l & 1) { amin(ret, d[l]); l++; }
	    if (r & 1) { r--; amin(ret, d[r]); }
	}
	return ret;
    }

    int min_i(int l, int r) const {
	return first_less_equal(l, min_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) < v: return i;
    // return npos;
    int first_less_than(int l, const T v) const {
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (d[l] < v) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (d[l*2] < v) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [l .. n-1]:
    //   if at(i) <= v: return i;
    // return npos;
    int first_less_equal(int l, const T v) const { 
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (d[l] <= v) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (d[l*2] <= v) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }


    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_than(int r, const T v) const {
	if (r < m) {
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (d[r] < v) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (d[1] < v) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (d[r*2+1] < v) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }

    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_equal(int r, const T v) const { 
	if (r < m) { 
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (d[r] <= v) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (d[1] <= v) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (d[r*2+1] <= v) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }
};
const int MAXN = 500011;
int N;
int A[MAXN];
int Q;

struct Query {
    int l, r;
    int i;
    bool operator<(const Query &y) const {
	return r < y.r;
    }
} query[MAXN];
int ans[MAXN];
int last_pos[MAXN];

const int INF = 1<<29;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &Q);
    REP (i, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	query[i].l = l;
	query[i].r = r;
	query[i].i = i;
    }

    memset(last_pos, -1, sizeof last_pos);

    sort(query, query+Q);
    RMQ<int> rmq(N, INF);
    for (int i=0, qi=0; ; i++) {
	while (qi < Q && query[qi].r <= i) {
	    int pos = rmq.min_i(query[qi].l, query[qi].r);
	    int val = rmq.at(pos);
	    if (val < query[qi].l) {
		ans[query[qi].i] = A[pos];
	    }
	    qi++;
	}

	if (i == N) break;

	if (last_pos[A[i]] >= 0) {
	    rmq.modify(last_pos[A[i]], INF);
	}
	rmq.modify(i, last_pos[A[i]]);
	last_pos[A[i]] = i;
    }

    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}