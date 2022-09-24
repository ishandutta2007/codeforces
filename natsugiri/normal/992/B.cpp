#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}



LL L, R, X, Y;

void MAIN() {
    scanf("%lld%lld%lld%lld", &L, &R, &X, &Y);

    if (Y % X) {
	puts("0");
	return;
    }

    LL T = Y / X;
    LL ans = 0;
    for (LL a=1; a*a<=T; a++) {
	if (L <= a*X && a*X <= R) {
	    LL b = T / a;
	    if (L <= b*X && b*X <= R && a*b == T && gcd(a, b) == 1u) {
		ans++;
		if (a<b) ans++;
	    }
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