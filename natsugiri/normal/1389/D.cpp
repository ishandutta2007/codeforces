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

int N;
LL K;
LL L1, R1, L2, R2;

void MAIN() {
    scanf("%d%lld", &N, &K);
    scanf("%lld%lld%lld%lld", &L1, &R1, &L2, &R2);

    if (L2 < L1) {
	swap(L1, L2);
	swap(R1, R2);
    }

    LL ans = 1LL<<60;
    // L1 <= L2;
    LL base;
    LL cost;
    LL value;
    if (L2 <= R1) {
	cost = 0;
	base = min(R1, R2) - L2;
	value = max(R1, R2) - L1 - base;
	base *= N;

	if (base >= K) amin(ans, 0LL);
	else amin(ans, (K-base)*2);
    } else {
	cost = L2 - R1;
	base = 0;
	value = max(R1, R2) - L1;
    }

    if (K > base) {
	for (int i=1; i<=N; i++) {
	    LL v = value * i;
	    if (v >= K - base) {
		amin(ans, i * cost + K - base);
	    } else {
		amin(ans, i * cost + v + (K - base - v) * 2);
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}