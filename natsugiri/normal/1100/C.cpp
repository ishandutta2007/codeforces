#include<cmath>
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
const double PI = acos(-1);

int N, r;
double C;

double sq(double x) { return x * x; }
bool ok(double mid) {
    double x = sqrt(max(0.0, sq(r + mid) - sq(mid)));
    double theta = acos(x / (r + mid));
    return PI/N < theta;
}

void MAIN() {
    scanf("%d%d", &N, &r);
    C = cos(2 * PI / N);
    double lo = 0, hi = 1.0;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    REP (i, 50) {
	double mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%.12f\n", lo);
//    eprintf("%.12f\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}