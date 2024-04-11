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

template<class T> struct IRMQ {
    int n; T *d;
    IRMQ() : n(0), d(NULL) {}
    template<class Iter> IRMQ(Iter begin, Iter end) : n(0), d(0) { build(begin, end); }
    IRMQ(const IRMQ &y) : n(y.n), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRMQ(IRMQ &&y) : n(0), d(NULL) { swap(*this, y); }
    ~IRMQ() { if (n) { n = 0; delete d; d = NULL; } }
    friend void swap(IRMQ &x, IRMQ &y) { swap(x.n, y.n); swap(x.d, y.d); }
    IRMQ& operator=(IRMQ y) { swap(*this, y); return *this; }

    template<class Iter> void build(Iter begin, Iter end) { // random access iterator
	n = end - begin;
	if (n == 0) return;
	int g = __lg(n);
	d = new T[n*(g+1)];
	REP (i, n) { d[i] = *begin; ++begin; }
	for (int t=0, b=0; t<g; t++, b+=n) for (int i=0, j=1<<t; j<=n-(1<<t); i++, j++)
	    d[b+n+i] = (d[b+j] < d[b+i]? d[b+j]: d[b+i]);
    }

    const T at(int i) const { return d[i]; }

    const T min_v(int l, int r) const {
	int g = __lg(r - l), b = n * g;
	r -= 1<<g;
	return d[b+r] < d[b+l]? d[b+r]: d[b+l];
    }

};

int N;
int L[200011], R[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", L+i, R+i), R[i]++;

    VI unq;
    REP (i, N) {
	unq.push_back(L[i]);
	unq.push_back(R[i]);
    }

    sort(unq.begin(), unq.end());
    unq.erase(unique(unq.begin(), unq.end()), unq.end());
    VI Z(unq.size());

    REP (i, N) {
	L[i] = lower_bound(unq.begin(), unq.end(), L[i]) - unq.begin();
	R[i] = lower_bound(unq.begin(), unq.end(), R[i]) - unq.begin();
    }
    REP (i, N) {
	Z[L[i]]++;
	Z[R[i]]--;
    }

    REP (i, (int)Z.size()-1) Z[i+1] += Z[i];

    IRMQ<int> rmq(Z.begin(), Z.end());

    REP (i, N) {
	int m = rmq.min_v(L[i], R[i]);
	if (m > 1) {
	    printf("%d\n", i+1);
	    return;
	}
    }
    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}