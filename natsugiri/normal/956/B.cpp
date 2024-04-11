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

int N;
int U;
int E[100011];

int de[200011];
int le, ri;

double eval(int i, double W) {
    return E[i] * W - E[i+1];
}

bool ok(double W) {
    le = ri = 0;

    for (int i=2; i<N; i++) {
	while (le < ri && eval(de[ri-1], W) <= eval(i-2, W)) ri--;
	de[ri++] = i-2;
	while (le < ri && E[i] - E[de[le]] > U) le++;
	if (le < ri) {
	    double val = (1.0-W)*E[i] + eval(de[le], W);
	    if (val >= 0) return true;
	}
    }

    return false;
}

void MAIN() {
    scanf("%d%d", &N, &U);
    REP (i, N) scanf("%d", E+i);

    double lo = 0.0, hi = 1.0;

    REP ($, 40) {
	double mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    if (ok(lo)) printf("%.15f\n", (lo+hi)/2);
    else puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}