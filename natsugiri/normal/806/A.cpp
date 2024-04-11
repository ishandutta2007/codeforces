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

LL x, y, p, q;
bool ok(LL k) {
    return x <= k * p && y <= k * q && k * p - x <= k * q - y;
}
void MAIN() {
    scanf("%lld%lld%lld%lld", &x, &y, &p, &q);

    if (x < y && p == q) { // p/q == 1;
	puts("-1");
    } else if (x > 0 && p == 0) { // p/q == 0;
	puts("-1");
    } else {
	LL lo = 0, hi = 1;

	while (!ok(hi)) {
	    lo = hi; hi += hi;
	}
	while (hi - lo > 1) {
	    LL mid = (hi + lo) / 2;
	    (ok(mid)? hi: lo) = mid;
	}

	printf("%lld\n", hi * q - y);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}