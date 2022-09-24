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

const double INF = 1e12;
const double GR = (sqrt(5) - 1.0) / 2.0; // GR == 0.618
// Func = double(*)(double);
template<class Func> double argmax(Func f, double lo = -INF, double hi = INF, const int LOOP = 60) {
    double x = hi - GR * (hi - lo), y = lo + GR * (hi - lo);
    double vx = f(x), vy = f(y);
    for (int i=0; i<LOOP; i++) {
	if (vx < vy) { lo = x; x = y; vx = vy; y = lo + GR * (hi - lo); vy = f(y); }
	else { hi = y; y = x; vy = vx; x = hi - GR * (hi - lo); vx = f(x); }
    }
    return (x+y)/2.0;
}

int N;
double theta;
double r;
double calc(double add) {

    double y0, y1, x0, x1;
    y0 = y1 = x0 = x1 = 0;
    REP (i, N) {
	double a = theta*i + add;
	double y = sin(a) * r;
	double x = cos(a) * r;
	amin(y0, y);
	amax(y1, y);
	amin(x0, x);
	amax(x1, x);
    }

    return -max(y1-y0, x1-x0);
}

void solve(int N_) {
    N = N_ * 2;

    theta = 2*PI / N;

    r = sqrt(0.5 / (1.0 - cos(theta)));

    double ans = r*2;
    amin(ans, -calc(0));
    amin(ans, -calc(theta/2));

    double add = argmax(calc, 0, theta/2, 60);
    amin(ans, -calc(add));


    printf("%.12f\n", ans);
}

void MAIN() {
    int N;
    scanf("%d", &N);
    solve(N);
}

int main() {
#ifdef LOCAL
    //for (int i=3; i<=199; i+=2) solve(i);
#endif
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}