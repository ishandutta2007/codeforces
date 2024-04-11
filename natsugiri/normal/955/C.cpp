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

LL powLL(LL x, LL y) {
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) r *= x;
	x *= x;
    }
    return r;
}

const LL HI[61] = 
{ -1, -1, 1000000001LL, 1000001, 31623, 3982, 1001, 373, 178, 101, 64, 44, 32, 25, 20, 16, 14, 12, 11, 9, 8, 8, 7, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
    
const LL mu[61] =
{ -100, 0, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0};

LL F(LL R) {
    LL ret = 0;
    LL lo = 0, hi = HI[2];
    for (int p=2; p<=59; p++) {
	if (hi <= 2) break;
	if (mu[p] == 0) continue;
	amin(hi, HI[p]);
	lo = 0;
	while (hi - lo > 1) {
	    LL mid = (hi + lo) / 2;
	    if (powLL(mid, p) > R) hi = mid;
	    else lo = mid;
	}

	if (lo > 0) ret += -mu[p] * (lo-1);
    }
    if (R >= 1) ret++;
    return ret;
//
//    2, 1 4 9 16 25;
//    3, 1 8 27;
//    4, 1 16;
//    5, 
}


void MAIN() {
    LL L, R;
    scanf("%lld%lld", &L, &R);
    LL ans = F(R) - F(L-1);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}