#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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
LL A[300011];

LL dp[300011];
const LL INF = 1LL<<60;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    RMQ<LL> ev(N+1), od(N+1);
    LL OD_ADD = 0, EV_ADD = 0;
    REP (i, N) {
	if (i % 2 == 0) od.modify(i, INF);
	else ev.modify(i, INF);
    }

    LL ans = 0;
    dp[0] = 1;

    REP (i, N) {
	int p = -1, q = -1;
	if (i % 2 == 0) {
	    ev.modify(i, -EV_ADD);
	    EV_ADD += A[i];
	    OD_ADD -= A[i];
	    p = od.last_less_equal(i+1, -OD_ADD);
	    q = ev.last_less_equal(i+1, -EV_ADD);
	} else {
	    od.modify(i, -OD_ADD);
	    OD_ADD += A[i];
	    EV_ADD -= A[i];
	    p = od.last_less_equal(i+1, -OD_ADD);
	    q = ev.last_less_equal(i+1, -EV_ADD);
	}

	int m = max(p, q);
	dp[i+1] = 1;
	if (m != -1) {
	    if (m % 2 == 0) {
		if (ev.at(m) + EV_ADD == 0) {
		    ans += dp[m];
		    dp[i+1] = dp[m] + 1;
		}
	    } else {
		if (od.at(m) + OD_ADD == 0) {
		    ans += dp[m];
		    dp[i+1] = dp[m] + 1;
		}
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}