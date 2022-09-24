#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

LL A, B;

void MAIN() {
    scanf("%lld%lld", &A, &B);
    A = abs(A - B);
    LL lo = 0, hi = 1000000;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	if (mid * (mid + 1) / 2 > A) hi = mid;
	else lo = mid;
    }

    while (1) {
	LL m = lo * (lo + 1) / 2;
	if (m < A || A % 2 != m % 2) lo++;
	else break;
    }
    printf("%lld\n", lo);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}