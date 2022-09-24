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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<class T> struct IRMQ {
    static const int npos = -1;

    int n, g; T *d;
    IRMQ() : n(0), g(0), d(NULL) {}
    template<class Iter> IRMQ(Iter begin, Iter end) : n(0), g(0), d(0) { build(begin, end); }
    IRMQ(const IRMQ &y) : n(y.n), g(0), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRMQ(IRMQ &&y) : n(0), g(0), d(NULL) { swap(*this, y); }
    ~IRMQ() { if (n) { n = 0; delete d; d = NULL; } }
    friend void swap(IRMQ &x, IRMQ &y) { swap(x.n, y.n); swap(x.g, y.g); swap(x.d, y.d); }
    IRMQ& operator=(IRMQ y) { swap(*this, y); return *this; }

    template<class Iter> void build(Iter begin, Iter end) { // random access iterator
	n = end - begin;
	if (n == 0) return;
	g = __lg(n);
	d = new T[n*(g+1)];
	REP (i, n) { d[i] = *begin; ++begin; }
	for (int t=0, b=0; t<g; t++, b+=n) for (int i=0, j=1<<t; j<=n-(1<<t); i++, j++)
	    d[b+n+i] = (d[b+j] < d[b+i]? d[b+j]: d[b+i]);
    }

    const T at(int i) const { return d[i]; }

    const T min_v(int l, int r) const {
	int h = __lg(r - l), b = n * h;
	r -= 1<<h;
	return d[b+r] < d[b+l]? d[b+r]: d[b+l];
    }

    int min_i(int l, int r) const {
	return first_less_equal(l, min_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) < v: return i;
    // return npos;
    int first_less_than(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && !(d[n*t+l] < v))
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [l .. n-1]:
    //   if at(i) <= v: return i;
    // return npos;
    int first_less_equal(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && v < d[n*t+l])
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_than(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && !(d[n*t+r-(1<<t)] < v))
		r -= 1 << t;
	return r? r-1: npos;
    }

    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_equal(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && v < d[n*t+r-(1<<t)])
		r -= 1 << t;
	return r? r-1: npos;
    }
};

int N, M, Q;
int P[200011];
int R[200011];
int A[200011];

int nxt[18][200011];
int B[200011];
int last[200011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) {
	int p;
	scanf("%d", &p);
	p--;
	P[i] = p;
	R[p] = i;
    }

    REP (i, M) {
	int a;
	scanf("%d", &a);
	a--;
	A[i] = a;
    }

    REP (i, N) last[i] = M;

    for (int i=M; i--;) {
	int w = P[(R[A[i]] + 1) % N];
	nxt[0][i] = last[w];
	last[A[i]] = i;
    }
    nxt[0][M] = M;

    REP (t, 17) REP (i, M+1) nxt[t+1][i] = nxt[t][nxt[t][i]];

    REP (i, M) {
	int step = N-1;
	int s = i;
	REP (t, 18) if (step>>t&1) s = nxt[t][s];
	B[i] = s;
    }
    IRMQ<int> rmq(B, B+M);

    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;

	int val = rmq.min_v(l, r);
	if (val < r) putchar('1');
	else putchar('0');
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}