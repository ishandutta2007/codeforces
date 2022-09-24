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

int N, P;
int A[100111];
int B[100111];

bool inf() {
    LL sum = 0;
    REP (i, N) sum += A[i];
    return sum <= P;
}

bool ok(double tt) {
    double need = 0;
    REP (i, N) need += max(0.0, A[i] * tt - B[i]);
    return need <= P * tt;
}

void MAIN() {
    scanf("%d%d", &N, &P);
    REP (i, N) scanf("%d%d", A+i, B+i);

    if (inf()) {
	puts("-1");
    } else {
	double lo = 0, hi = 1;
	while (ok(hi)) {
	    lo = hi;
	    hi *= 2;
	}
	REP (_, 200) {
	    double mid = (lo + hi) / 2;
	    (ok(mid)? lo: hi) = mid;
	}
	printf("%.9f\n", (lo + hi) / 2);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}