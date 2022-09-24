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

int N, Q;
int C[1501][1501];


struct Arr {
    int len;
    int c[11];
    Arr() {
	len = 0;
    }

};
Arr join(Arr &a, Arr &b) {
    Arr ret;
    ret.len = 0;

    if (a.len >= 11 || b.len >= 11) {
	ret.len = 11;
	return ret;
    }

    int i = 0, j = 0;
    while (i < a.len && j < b.len) {
	if (a.c[i] == b.c[j]) {
	    ret.c[ret.len++] = a.c[i];
	    i++;
	    j++;
	} else if (a.c[i] < b.c[j]) {
	    ret.c[ret.len++] = a.c[i];
	    i++;
	} else {
	    ret.c[ret.len++] = b.c[j];
	    j++;
	}

	if (ret.len >= 11) return ret;
    }

    while (i < a.len) {
	ret.c[ret.len++] = a.c[i];
	i++;
	if (ret.len >= 11) return ret;
    }

    while (j < b.len) {
	ret.c[ret.len++] = b.c[j];
	j++;
	if (ret.len >= 11) return ret;
    }

    return ret;
}

Arr X[1501][1501];
Arr tmp0, tmp1, tmp2, bk;
bool fix[1501][1501];

int ans[2011];

void solve(int i, int j, int s, int lo, int hi) {
    int sh = 1<<s;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	// int s = __lg(mid);

	int i0 = i + mid - sh;
	int j0 = j + mid - sh;
	tmp0 = join(X[i][j], X[i][j0]);
	tmp1 = join(X[i0][j], X[i0][j0]);
	tmp2 = join(tmp0, tmp1);
	if (tmp2.len <= Q) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }

    ans[1]++;
    ans[hi]--;
}

void MAIN() {
    scanf("%d%d", &N, &Q);

    REP (i, N) REP (j, N) {
	scanf("%d", C[i]+j);
    }

#ifdef LOCAL
    N = 1500;
    Q = 10;
    REP (i, N) REP (j, N) {
	C[i][j] = rand() % 10;
    }
#endif

    REP (i, N) REP (j, N) {
	X[i][j].len = 1;
	X[i][j].c[0] = C[i][j];
    }

    for (int s=0; s<=10; s++) {
	int sh = 1<<s;
	REP (i, N) REP (j, N) {
	    if (i + sh * 2 <= N && j + sh * 2 <= N) {
		tmp0 = join(X[i][j], X[i][j+sh]);
		tmp1 = join(X[i+sh][j], X[i+sh][j+sh]);
		bk = join(tmp0, tmp1);

		if (!fix[i][j] && bk.len > Q) {
		    int lo = sh;
		    int hi = sh * 2;
		    solve(i, j, s, lo, hi);

		    fix[i][j] = true;
		}

		X[i][j] = bk;
	    } else {
		if (!fix[i][j]) {
		    int lo = sh;
		    int hi = min(N-i, N-j) + 1;
		    solve(i, j, s, lo, hi);

		    fix[i][j] = true;
		}

		X[i][j].len = 11;
	    }
	}
    }


    REP (k, N) ans[k+1] += ans[k];
    for (int k=1; k<=N; k++) printf("%d\n", ans[k]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}