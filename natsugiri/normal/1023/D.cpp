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
};

int N, Q;
int A[200111];

int L[200111], R[200111];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    RMQ<int> rmq; rmq.build(A, A+N);

    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    REP (i, N) R[A[i]] = i;
    for (int i=N; i--;) L[A[i]] = i;

    bool yes = true;

    for (int q=Q; yes && q>=1; q--) {
	if (L[q] == -1) {
	    if (q == Q) {
		int k = rmq.min_i(0, N);
		if (A[k] == 0) {
		    A[k] = q;
		    rmq.modify(k, q);
		} else {
		    yes = false;
		}
	    }
	} else {
	    while (1) {
		int k = rmq.min_i(L[q], R[q]+1);
		if (A[k] == 0) {
		    A[k] = q;
		    rmq.modify(k, q);
		} else if (A[k] == q) {
		    break;
		} else {
		    yes = false;
		    break;
		}
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, N) if (A[i] == 0) A[i] = 1;
	rprintf("%d", A, A+N);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}