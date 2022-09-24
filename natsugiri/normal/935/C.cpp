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

LL sq(LL x) { return x*x; }
LL norm(LL x, LL y, LL s, LL t) {
    return sq(x - s) + sq(y - t);
}

LL R, X1, Y1, X2, Y2;
double X3, Y3, R3;

void MAIN() {
    scanf("%lld%lld%lld%lld%lld", &R, &X1, &Y1, &X2, &Y2);

    LL D2 = norm(X1, Y1, X2, Y2);
    if (D2 >= sq(R)) {
	X3 = X1;
	Y3 = Y1;
	R3 = R;
    } else if (X1 == X2 && Y1 == Y2) {
	X3 = X1;
	Y3 = Y1 + R / 2.0;
	R3 = R / 2.0;
    } else {
	double D = sqrt(D2);
	double w = (D + R) / 2.0 / D;
	X3 = X2 + (X1 - X2) * w;
	Y3 = Y2 + (Y1 - Y2) * w;
	R3 = (D + R) / 2.0;
    }

    printf("%.12f %.12f %.12f\n", X3, Y3, R3);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}