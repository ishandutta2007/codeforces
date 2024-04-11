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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int L;
int A[100011];

double dist0, dist1;
double ok(double mid) {
    int prv = 0;
    int v = 1;
    double T = mid;
    dist0 = 0;
    for (int i=1; i<N; i++) {
	double d = A[i] - prv;
	double t = d / v;
	if (T >= t) {
	    dist0 = A[i];
	    T -= t;
	} else {
	    dist0 += T * v;
	    break;
	}
	prv = A[i];
	v++;
    }

    prv = L;
    v = 1;
    T = mid;
    dist1 = 0;
    for (int i=N-2; i>=0; i--) {
	double d = prv - A[i];
	double t = d / v;
	if (T >= t) {
	    dist1 = L - A[i];
	    T -= t;
	} else {
	    dist1 += T * v;
	    break;
	}
	prv = A[i];
	v++;
    }

    return dist0 + dist1 >= L;
}

void MAIN() {
    scanf("%d%d", &N, &L);
    REP (i, N) scanf("%d", A+i+1);
    N += 2;
    A[0] = 0;
    A[N-1] = L;


    double lo = 0, hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    REP (t, 70) {
	double mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%.20f\n", (hi+lo)/2);
    //eprintf("%f %f\n", dist0, dist1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}