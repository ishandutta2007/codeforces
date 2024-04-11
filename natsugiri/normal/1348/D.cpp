#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL N;

LL A[1001];
bool ok(LL D) {
    if (D+1 >= N) return true;
    LL sum = D + 1;
    LL cnt = 1;
    REP (i, D) {
	A[i] = min(cnt, (N - sum) / (D - i));
	sum += A[i] * (D-i);
	cnt += A[i];
    }

    return sum == N;
}

void MAIN() {
    scanf("%lld", &N);
    LL lo = 0, hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    memset(A, 0, sizeof A);
    ok(hi);
    printf("%lld\n", hi);
    rprintf("%lld", A, A+hi);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}