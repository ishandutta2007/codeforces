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

struct SetSum {
    typedef long long T;
    int N, M;
    vector<bool> zero;
    vector<T> all;
    vector<T> part;
    // all and zero are lazy
    SetSum(int N): N(N) {
        M = 1;
        for (; M<N;) M *= 2;
        all = part = vector<T>(M*2);
        zero = vector<bool>(M*2, false);
    }
    void force(int k) {
        if (zero[k]) {
            if (k<M) zero[k*2] = zero[k*2+1] = true;
            zero[k] = false;
            all[k] = part[k] = 0;
        }
    }
    void add(int x, int y, T v) { add(x, y, 1, 0, M, v); }
    T add(int x, int y, int k, int l, int r, T v) {
        force(k);
        if (x<=l && r<=y) {
            all[k] += v;
        } else if (x<r && l<y) {
            part[k] = 0;
            part[k] += add(x, y, k*2, l, (l+r)/2, v);
            part[k] += add(x, y, k*2+1, (l+r)/2, r, v);
        }
        return (r-l)*all[k] + part[k];
    }
    void set(int x, int y, T v) {
        reset(x, y, 1, 0, M, 0);
        add(x, y, 1, 0, M, v);
    }
    void reset(int x, int y) { reset(x, y, 1, 0, M, 0); }
    T reset(int x, int y, int k, int l, int r, T v) {
        force(k);
        if (x<=l && r<=y) {
            zero[k] = true;
            all[k] = part[k] = 0;
        } else if (x<r && l<y) {
            part[k] = 0;
            part[k] += reset(x, y, k*2, l, (l+r)/2, v + all[k]);
            part[k] += reset(x, y, k*2+1, (l+r)/2, r, v + all[k]);
            all[k] = 0;
        } else {
            force(k);
            all[k] += v;
        }
        return (r-l)*all[k] + part[k];
    }
    T sum(int x, int y) { return sum(x, y, 1, 0, M); }
    T sum(int x, int y, int k, int l, int r) {
        force(k);
        if (r<=x || y<=l) return 0;
        if (x<=l && r<=y) return (r-l)*all[k] + part[k];
        return (min(y, r)-max(x, l)) * all[k] +
            sum(x, y, k*2, l, (l+r)/2) +
            sum(x, y, k*2+1, (l+r)/2, r);
    }
};
template<class T> struct IRXQ {
    static const int npos = -1;

    int n, g; T *d;
    IRXQ() : n(0), g(0), d(NULL) {}
    template<class Iter> IRXQ(Iter begin, Iter end) : n(0), g(0), d(0) { build(begin, end); }
    IRXQ(const IRXQ &y) : n(y.n), g(0), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRXQ(IRXQ &&y) : n(0), g(0), d(NULL) { swap(*this, y); }
    ~IRXQ() { if (n) { n = 0; delete[] d; d = NULL; } }
    friend void swap(IRXQ &x, IRXQ &y) { swap(x.n, y.n); swap(x.g, y.g); swap(x.d, y.d); }
    IRXQ& operator=(IRXQ y) { swap(*this, y); return *this; }

    template<class Iter> void build(Iter begin, Iter end) { // random access iterator
	n = end - begin;
	if (n == 0) return;
	g = __lg(n);
	d = new T[n*(g+1)];
	REP (i, n) { d[i] = *begin; ++begin; }
	for (int t=0, b=0; t<g; t++, b+=n) for (int i=0, j=1<<t; j<=n-(1<<t); i++, j++)
	    d[b+n+i] = (d[b+i] < d[b+j]? d[b+j]: d[b+i]);
    }

    const T at(int i) const { return d[i]; }

    const T max_v(int l, int r) const {
	int h = __lg(r - l), b = n * h;
	r -= 1<<h;
	return d[b+l] < d[b+r]? d[b+r]: d[b+l];
    }

    int max_i(int l, int r) const {
	return first_more_equal(l, max_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) > v: return i;
    // return npos;
    int first_more_than(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && !(v < d[n*t+l]))
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [l .. n-1]:
    //   if v <= at(i): return i;
    // return npos;
    int first_more_equal(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && d[n*t+l] < v)
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [r-1 .. 0]:
    //   if v < at(i): return i;
    // return npos;
    int last_more_than(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && !(v < d[n*t+r-(1<<t)]))
		r -= 1 << t;
	return r? r-1: npos;
    }

    // for i in [r-1 .. 0]:
    //   if v <= at(i): return i;
    // return npos;
    int last_more_equal(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && d[n*t+r-(1<<t)] < v)
		r -= 1 << t;
	return r? r-1: npos;
    }
};


int N;
int A[200011];
int Q;
int P[200011];
int X[200011];
VI qu[200011];
LL ans[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;
    scanf("%d", &Q);
    REP (i, Q) scanf("%d%d", P+i, X+i), P[i]--, X[i]--;

    REP (i, N) {
	A[i] = i - A[i];
	amin(A[i], i+1);
    }
    REP (i, Q) {
	X[i] = P[i] - X[i];
	amin(X[i], P[i]+1);
	qu[P[i]].push_back(i);
    }

    SetSum tree(N);
    tree.set(0, N, N);
    IRXQ<int> rxq(A, A+N);


    for (int i=N; i--;) {
	int left = 0;
	if (i) {
	    amax(left, rxq.max_v(0, i));
	}

	LL base = tree.sum(left, N);
	EACH (e, qu[i]) {
	    int to = X[*e];
	    if (left < to) {
		ans[*e] = base - tree.sum(left, to) + (LL)i * (to - left);
	    } else {
		ans[*e] = base;
	    }
	}

	if (A[i] > 0) {
	    tree.set(0, A[i], i);
	}
    }

//    REP (i, N) printf("%lld ", tree.sum(i, i+1));
//    puts("");

    LL base = (LL)N * (N-1) / 2;
    REP (i, Q) {
	int left = 0;
	if (P[i]) {
	    amax(left, rxq.max_v(0, P[i]));
	}
	if (left) {
	    ans[i] += tree.sum(0, left);
	}
	LL out = ans[i] - base;
	printf("%lld\n", out);
    }
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}