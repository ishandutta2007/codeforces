#include<cassert>
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

ULL N, M;

ULL safe(ULL x, ULL y) {
    if (x & 1) y >>= 1;
    else x >>= 1;
    LL r = 0;
    for (; y; y>>=1) {
	if (y&1) r = min(N, r + x);
	x = min(N, x + x);
    }
    return r;
}
bool ok(ULL t) {
    if (N <= t) return false;
    if (t <= M) return true;
    return safe(t - M, t - M - 1) + t < N;
}

int main() {
    scanf("%llu %llu", &N, &M);
    amin(M, N);

    ULL lo = 0, hi = 1;
    while (ok(hi)) hi <<= 1;
    while (hi - lo > 1) {
	ULL mid = (lo + hi) / 2;
	(ok(mid) ? lo : hi) = mid;
    }

    printf("%llu\n", hi);

    return 0;
}