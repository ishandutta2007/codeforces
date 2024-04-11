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

template<class T> struct IRXQ {
    int n, g; T *d;
    IRXQ() : n(0), g(0), d(NULL) {}
    template<class Iter> IRXQ(Iter begin, Iter end) : n(0), g(0), d(0) { build(begin, end); }
    IRXQ(const IRXQ &y) : n(y.n), g(0), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRXQ(IRXQ &&y) : n(0), g(0), d(NULL) { swap(*this, y); }
    ~IRXQ() { if (n) { n = 0; delete d; d = NULL; } }
    friend void swap(IRXQ &x, IRXQ &y) { swap(x.n, y.n); swap(x.d, y.d); }
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
};

int N, K;
int A[200111];
int pos[200111];
IRXQ<int> rxq;

bool rec(int L, int R, int low, int high) {
    if (L >= R) return true;

    if (pos[high] != -1) {
	int p = pos[high];
	int ma;
	if (L < p) {
	    ma = rxq.max_v(L, p);
	    if (p - L != ma - low + 1) return false;
	    if (!rec(L, p, low, ma)) return false;
	} else {
	    ma = low - 1;
	}

	if (!rec(p+1, R, ma+1, high-1)) return false;
    } else if (L < K) {
	int ma = rxq.max_v(L, K);
	int p = L + (ma - low + 1);
	A[p] = high;
	if (!rec(L, p, low, ma)) return false;
	if (!rec(p+1, R, ma+1, high-1)) return false;
    } else {
	while (L < R) {
	    if (pos[high] != -1) return false;
	    A[L++] = high;
	    high--;
	}
    }
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, K) scanf("%d", A+i);

    memset(pos, -1, sizeof pos);
    REP (i, K) pos[A[i]] = i;
    rxq = IRXQ<int>(A, A+K);


    if (rec(0, N, 1, N)) {
	rprintf("%d", A, A+N);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}