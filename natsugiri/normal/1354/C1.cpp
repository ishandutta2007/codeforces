#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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
const double PI = acos(-1);


void MAIN() {
    int N;
    scanf("%d", &N);

    N *= 2;
    double theta = 2*PI / N;

    double r = sqrt(0.5 / (1.0 - cos(theta)));

    double ans = r*2;
    double y0, y1, x0, x1;
    y0 = y1 = x0 = x1 = 0;
    REP (i, N) {
	double a = theta*i + theta/2;
	double y = sin(a) * r;
	double x = cos(a) * r;
	amin(y0, y);
	amax(y1, y);
	amin(x0, x);
	amax(x1, x);
    }

    double tmp = max(y1-y0, x1-x0);
    amin(ans, tmp);
    printf("%.12f\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}