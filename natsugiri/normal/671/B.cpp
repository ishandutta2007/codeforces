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

int N, K;
LL A[500111];

LL calc() {
    LL lo = -1LL<<40, hi = 1LL<<40;
    
    while (hi - lo > 1) {
	LL m = (hi + lo) / 2;
	LL s = 0;
	REP (i, N) if (A[i] > m) s += A[i] - m;
	(s <= K? hi: lo) = m;
    }
    return hi;
}

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lld", A+i);

    LL hi = calc();
    REP (i, N) A[i] = -A[i];
    LL lo = -calc();

    LL s = 0;
    REP (i, N) s += A[i];
    if (hi <= lo) puts(s % N == 0 ? "0": "1");
    else printf("%lld\n", hi - lo);

    return 0;
}