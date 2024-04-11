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
LL A, B;
LL X[100011];

LL rec(LL lo, LL hi, int l, int r) {
    if (l == r) return A;
    LL cst = B * (r-l) * (hi-lo);
    if (lo + 1 < hi) {
	LL mid = (lo + hi) >> 1;
	int k = lower_bound(X+l, X+r, mid) - X;
	amin(cst, rec(lo, mid, l, k) + rec(mid, hi, k, r));
    }
    return cst;
}

void MAIN() {
    scanf("%d%d%lld%lld", &N, &K, &A, &B);
    REP (i, K) scanf("%lld", X+i), X[i]--;
    sort(X, X+K);

    LL ans = rec(0, 1LL<<N, 0, K);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}