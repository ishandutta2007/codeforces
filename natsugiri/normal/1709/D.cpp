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
int HI;
int LEN;
int A[200011];
IRXQ<int> rxq;

pair<int, int> F(int x, int y, int k) {
    x += (HI - x) / k * k;

    int pos = rxq.last_more_equal(y, x) + 1;
    y -= (y - pos) / k * k;
    return make_pair(x, y);
}

void MAIN() {
    scanf("%d%d", &HI, &LEN);
    REP (i, LEN) scanf("%d", A+i);

    rxq = IRXQ<int>(A, A+LEN);

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int xs, ys, xf, yf, k;
	scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);
	ys--; yf--;

	if (F(xs, ys, k) == F(xf, yf, k)) {
	    puts("YES");
	} else {
	    puts("NO");
	}
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}