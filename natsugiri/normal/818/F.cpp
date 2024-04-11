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

LL N;

void MAIN() {
    scanf("%lld", &N);

    LL lo = -1, hi = N-1;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	LL g = (N - mid) * (N - mid - 1) / 2;
	if (g <= mid) hi = mid;
	else lo = mid;
    }
    
    LL ans = 0;
    {
	LL g = (N - hi) * (N - hi - 1) / 2;
	ans = g + hi;
    }

    if (hi) {
	LL t = hi - 1;
	LL g = (N - t) * (N - t - 1) / 2;
	amax(ans, t + min(t, g));
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}