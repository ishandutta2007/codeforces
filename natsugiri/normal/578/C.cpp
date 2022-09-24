#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, A[200111];
double f(double x) {
    double ret = 0, lo = 0, hi = 0;
    REP (i, N) {
	lo += A[i] - x;
	hi += A[i] - x;
	amin(lo, 0.0);
	amax(hi, 0.0);
	amax(ret, hi);
	amax(ret, -lo);
    }
    return -ret;
}

const double GR = (sqrt(5) - 1.0) / 2.0; // GR == 0.618
double argmax() {
    double lo = -2e4, hi = 2e4;
    double x = hi - GR * (hi - lo), y = lo + GR * (hi - lo);
    double vx = f(x), vy = f(y);
    for (int i=0; i<501; i++) {
	if (vx < vy) { lo = x; x = y; vx = vy; y = lo + GR * (hi - lo); vy = f(y); }
	else { hi = y; y = x; vy = vx; x = hi - GR * (hi - lo); vx = f(x); }
    }
    return (x+y)/2.0;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    // N = 200000;
    // REP (i, N) A[i] = rand() % 20000 - 10000;

    double a = argmax();

    printf("%.20f\n", -f(a));
    return 0;
}