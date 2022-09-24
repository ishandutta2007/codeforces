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

int N, K;
double L, V, W;

int main() {
    scanf("%d%lf%lf%lf%d", &N, &L, &V, &W, &K);

    N = (N + K - 1) / K;
    double lo = 0, hi = L;
    REP (i, 200) {
	double m = (lo + hi) / 2;
	double t = m / W;
	double s = t * (W - V) / (W + V);
	
	if (N * t - (N - 1) * s >= L / W) hi = m;
	else lo = m;

	if (i == 199) {
	    printf("%.9f\n", t * N + s * (N-1));
	    return 0;
	}
    }


    return 0;
}