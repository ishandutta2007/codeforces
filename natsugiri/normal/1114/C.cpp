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

ULL N, B;
ULL ans;

void check(ULL p, ULL de) {
    ULL s = 0;
    ULL n = N;
    while (n) {
	s += n / p;
	n /= p;
    }
//    eprintf("%llu %llu\n", s, de);
    amin(ans, s/de);
}

void MAIN() {
    scanf("%llu%llu", &N, &B);

    ans = ~0ULL;
    for (ULL i=2; i*i<=B; i++) {
	int cnt = 0;
	while (B % i == 0) {
	    cnt++;
	    B /= i;
	}
	if (cnt) {
	    check(i, cnt);
	}
    }
    if (B > 1) check(B, 1);

    printf("%llu\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}