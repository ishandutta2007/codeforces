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

int N, M;
int A[1011];
int B[1011];

bool ok(long double mid) {
    REP (i, N) {
	long double x = (mid + M) / A[i];
	if (x > mid) return false;
	mid -= x;
	x = (mid + M) / B[i+1];
	if (x > mid) return false;
	mid -= x;
    }

    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    B[N] = B[0];

    bool yes = ok(1e10);
    if (!yes) {
	puts("-1");
	return;
    }

    double lo = 0, hi = 1e10;
    REP (t, 300) {
	double mid = (hi + lo) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%.9f\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}