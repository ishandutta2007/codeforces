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

int N;
const LL INF = 1LL<<60;

int main() {
    scanf("%d", &N);
    LL lo = -INF, hi = INF;
    bool div2 = false;
    REP (I, N) {
	int C, D;
	scanf("%d%d", &C, &D);

	if (D == 1) amax(lo, 1900LL);
	if (D == 2) { amin(hi, 1899LL); div2 = true; }
	lo += C;
	hi += C;
    }

    if (hi < lo) puts("Impossible");
    else if (!div2) puts("Infinity");
    else printf("%lld\n", hi);



    return 0;
}