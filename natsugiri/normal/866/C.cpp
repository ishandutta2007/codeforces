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

const double INF = 1e100;
int N, R;
int F[55], S[55], P[55];
double E[55][5500];

bool ok(double e0) {
    for (int i=N; i--;) {
	for (int j=0; j<=R; j++) {
	    E[i][j] = INF;
	    if (S[i] <= j) {
		amin(E[i][j], 
			P[i] * (F[i] + E[i+1][j-F[i]]) / 100 +
			(100 - P[i]) * (S[i] + E[i+1][j-S[i]]) / 100);
	    }
	    if (F[i] <= j) {
		amin(E[i][j], 
			P[i] * (F[i] + E[i+1][j-F[i]]) / 100 +
			(100 - P[i]) * (S[i] + e0) / 100);
	    }
	}
    }

    return E[0][R] <= e0;
}

void MAIN() {
    scanf("%d%d", &N, &R);
    REP (i, N) scanf("%d%d%d", F+i, S+i, P+i);

    double lo = 0, hi = 1;
    while (!ok(hi)) hi += hi;
    REP (_, 200) {
	double mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%.12f\n", (lo + hi) / 2);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}