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

const int SIZE = 14;
LL A[SIZE];
LL B[SIZE];

void MAIN() {
    REP (i, SIZE) scanf("%lld", A+i);

    LL ans = 0;
    REP (s, SIZE) if (A[s]) {
	REP (i, SIZE) B[i] = A[i];
	LL q = B[s] / SIZE;
	LL r = B[s] % SIZE;
	B[s] = 0;
	REP (i, SIZE) B[(i+s+1)%SIZE] += q + (i<r? 1: 0);

	LL tmp = 0;
	REP (i, SIZE) if (~B[i] & 1) tmp += B[i];
	amax(ans, tmp);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}