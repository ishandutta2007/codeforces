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


void MAIN() {
    LL X;
    scanf("%lld", &X);

    if (X == 0) {
	puts("1 1");
	return;
    }

    for (LL i=1; i*i <= X; i++) {
	if (X % i == 0) {
	    LL s = i, t = X / i;
	    LL n = (s+t)/2, k = (t-s)/2;
	    if (k <= 0) continue;
	    LL m = n/k;

	    if (1 <= m && m <= n && n <= 1000000000
		    && n*n - (n/m)*(n/m) == X) {
		printf("%lld %lld\n", n, m);
		return;
	    }
	}
    }
    puts("-1");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}