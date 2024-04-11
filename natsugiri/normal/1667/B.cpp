#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

template<class T> struct RXQ {
    static const int npos = -1;

    static int ceil_pow2(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return 2<<__lg(n-1);
    }

    int n, m;
    vector<T> d;
    RXQ() {}

    RXQ(int n_, const T init=T()) : n(n_), m(ceil_pow2(n)), d(2*m, init) {
	build_with_initializer([init](int i) { return init; });
    }

    template<class Iter> RXQ(Iter begin, Iter end, const T init=T()): n(end-begin), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer([&](int i) {
		if (i < n) return *(begin+i);
		else return init;
		});
    }

    template<class Initializer> RXQ(int n_, Initializer func): n(n_), m(ceil_pow2(n)), d(2*m) {
	build_with_initializer(func);
    }

    template<class Initializer> inline void build_with_initializer(Initializer func) {
	// func(0) ... func(2^k-1);
	for (int i=0; i<m; i++) d[i+m] = func(i);
	for (int i=m; --i; ) d[i] = max(d[i*2+1], d[i*2]);
    }

    const T at(int i) const { return d[i+m]; }

    void modify(int i, const T v) {
	i += m; d[i] = v;
	for (i>>=1; i; i>>=1) d[i] = max(d[i*2+1], d[i*2]);
    }

    T max_v(int l, int r) const {
	l += m; r += m;
	T ret = d[l++];
	for (; l<r; l>>=1, r>>=1) {
	    if (l & 1) { amax(ret, d[l]); l++; }
	    if (r & 1) { r--; amax(ret, d[r]); }
	}
	return ret;
    }

    int max_i(int l, int r) const {
	return first_more_equal(l, max_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) > v: return i;
    // return npos;
    int first_more_than(int l, const T v) const {
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (v < d[l]) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (v < d[l*2]) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [l .. n-1]:
    //   if v <= at(i): return i;
    // return npos;
    int first_more_equal(int l, const T v) const { 
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (v <= d[l]) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (v <= d[l*2]) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [r-1 .. 0]:
    //   if v < at(i): return i;
    // return npos;
    int last_more_than(int r, const T v) const {
	if (r < m) {
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (v < d[r]) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (v < d[1]) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (v < d[r*2+1]) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }

    // for i in [r-1 .. 0]:
    //   if v <= at(i): return i;
    // return npos;
    int last_more_equal(int r, const T v) const { 
	if (r < m) { 
	    for (r+=m; 1<r; r>>=1) {
		if (r & 1) {
		    r--;
		    if (v <= d[r]) break;
		}
	    }
	    if (r <= 1) return npos;
	} else {
	    if (v <= d[1]) r = 1;
	    else return npos;
	}
	for (; r<m; ) {
	    if (v <= d[r*2+1]) r = r*2+1;
	    else r = r*2;
	}
	return r - m;
    }
};

int N;
LL A[500011];
LL sums[500011];
LL mem[500011];
const LL INF = 1LL<<60;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N) sums[i+1] = sums[i] + A[i];

    vector<LL> ss(sums, sums+N+1);
    sort_unique(ss);
    auto get = [ss](LL m) {
	return lower_bound(ss.begin(), ss.end(), m) - ss.begin();
    };

    REP (i, N+1) mem[i] = -INF;
    RXQ<LL> rxq_plus(ss.size(), -INF);
    RXQ<LL> rxq_minus(ss.size(), -INF);
    {
	int pos = get(0);
	rxq_plus.modify(pos, 0);
	rxq_minus.modify(pos, 0);
	mem[pos] = 0;
    }

    for (int i=1; i<=N; i++) {
	int pos = get(sums[i]);

	LL tmp = mem[pos];
	if (pos) amax(tmp, i + rxq_minus.max_v(0, pos));
	if (pos+1 < (int)ss.size()) amax(tmp, -i + rxq_plus.max_v(pos+1, ss.size()));


	if (i == N) {
	    printf("%lld\n", tmp);
	} else {
	    if (rxq_minus.at(pos) < tmp - i) rxq_minus.modify(pos, tmp - i);
	    if (rxq_plus.at(pos) < tmp + i) rxq_plus.modify(pos, tmp + i);
	    amax(mem[pos], tmp);
	}
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}