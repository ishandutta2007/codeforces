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

LL N, M, K;


int main() {
    scanf("%lld%lld%lld", &N, &M, &K);
    if (N + M - 2 < K) {
	puts("-1");
	return 0;
    }

    LL ans = 0;

    REP (t, 2) {
	for (LL a=1; a*a <= N; a++) {
	    LL b = K - a + 2;
	    if (b > 0) {
		amax(ans, (N / a) * (M / b));
	    }
	    LL d = N / a;
	    b = K - d + 2;
	    if (d > 0 && b > 0) {
		amax(ans, (N / d) * (M / b));
	    }
	}
	swap(N, M);
    }

    printf("%lld\n", ans);
    return 0;
}