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

int N, R;
int X[1011];
double Y[1011];

void MAIN() {
    scanf("%d%d", &N, &R);
    REP (i, N) scanf("%d", X+i);

    REP (i, N) {
	Y[i] = R;
	REP (j, i) {
	    int d = X[i] - X[j];
	    if (abs(d) <= 2 * R) {
		double s = sqrt(max(0.0, 4.0 * R * R - (double)d * d));
		amax(Y[i], Y[j] + s);
	    }
	}
    }

    rprintf("%.12f", Y, Y+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}