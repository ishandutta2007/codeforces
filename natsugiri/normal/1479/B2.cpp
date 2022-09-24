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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

template<class T> struct RMQ {
    static const int npos = -1;

    static int ceil_pow2(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return 2<<__lg(n-1);
    }

    int n, m;
    vector<T> d;
    RMQ() {}

    RMQ(int n_, const T init=T()) : n(n_), m(ceil_pow2(n)), d(2*m, init) {
	build_with_initializer([init](int i) { return init; });
    }

    template<class Iter> RMQ(Iter begin, Iter end, const T init=T()): n(end-begin), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer([&](int i) {
		if (i < n) return *(begin+i);
		else return init;
		});
    }

    template<class Initializer> RMQ(int n_, Initializer func): n(n_), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer(func);
    }

    template<class Initializer> void inline build_with_initializer(Initializer func) {
	// func(0) ... func(2^k-1);
	for (int i=0; i<m; i++) d[i+m] = func(i);
	for (int i=m; --i; ) d[i] = min(d[i*2+1], d[i*2]);
    }

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
int N;
int A[1000011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    RMQ<int> rmq(N+2, 1<<20);
    int all = 0;
    int prv = 0;
    rmq.modify(0, 0);

    REP (i, N) {
	int mi = all +
	    min(rmq.min_v(0, A[i]), rmq.min_v(A[i]+1, N+2));
	mi++;

	int tmp = all + rmq.at(A[i]);

	if (prv != A[i]) {
	    all++;
	}

	int cur = all + rmq.at(prv);

	if (cur > mi) {
	    rmq.modify(prv, mi - all);
	}

	cur = all + rmq.at(prv);
	if (cur > tmp) {
	    rmq.modify(prv, tmp - all);
	}

	prv = A[i];
    }

    int ans = rmq.min_v(0, N+2) + all;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}