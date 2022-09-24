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
int A[100011];
LL sums[100011];

LL calc(int l, int r) {
    if (r <= l) {
	return 0;
    } else if ((r-l) % 2 == 0) {
	return sums[r] - sums[l];
    } else {
	return sums[r-1] - sums[l];
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i+1);
    N++;
    A[N] = M;
    N++;

    REP (i, N) {
	sums[i+1] = A[i] - sums[i];
    }
//    rprintf("%d", A, A+N);
//    rprintf("%lld", sums, sums+N+1);

    LL ans = calc(0, N);

    REP (i, N-1) {
	if (A[i]+1 < A[i+1]) {
	    LL tmp = calc(0, i+1) + (A[i+1] - A[i] - 1);
	    if (i % 2 == 0) {
		tmp += calc(i+1, N);
	    } else {
		tmp += calc(i+2, N);
	    }
	    amax(ans, tmp);
	}
    }
    printf("%lld\n", ans);


}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}