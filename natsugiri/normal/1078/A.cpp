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

double sq(double x) { return x*x; }
double hypot(double x, double y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x < y) swap(x, y);
    return x * sqrt(1 + sq(y/x));
}

LL A, B, C;
LL X1, Y1, X2, Y2;

void MAIN() {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &A, &B, &C, &X1, &Y1, &X2, &Y2);

    double ans = abs(X1 - X2) + abs(Y1 - Y2);

    if (A != 0 && B != 0) {
	REP (p, 2) {
	    double x1, y1;
	    if (p == 0) {
		x1 = X1;
		y1 = (-A*x1 - C) / B;
	    } else {
		y1 = Y1;
		x1 = (-B*y1 - C) / A;
	    }

	    REP (q, 2) {
		double x2, y2;
		if (q == 0) {
		    x2 = X2;
		    y2 = (-A*x2 - C) / B;
		} else {
		    y2 = Y2;
		    x2 = (-B*y2 - C) / A;
		}

		double tmp =
		    abs(X1 - x1) + abs(Y1 - y1)
		    + hypot(x1 - x2, y1 - y2)
		    + abs(x2 - X2) + abs(y2 - Y2);
		amin(ans, tmp);
	    }
	}
    }

    printf("%.12f\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}