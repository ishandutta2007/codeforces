#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

void slow(LL X, LL Y) {
    LL ans = 0;
    for (LL b=1; b<=Y && b+1<=X; b++) {
	LL k = min(b-1, X/(b+1));
	if (k >= 1) {
	    assert(b * k + k <= X);
	    ans += k;
	}
    }

    eprintf("%lld\n", ans);
}

void MAIN() {
    LL X, Y;
    scanf("%lld%lld", &X, &Y);

    LL ans = 0;
    for (LL b=1; b<=100000 && b<=Y && b+1<=X; b++) {
	LL k = min(b-1, X/(b+1));
	ans += k;
    }

    for (LL k=1; k<=100000; k++) {
	// [lo, hi]
	// [100001, Y]
	LL hi = min(Y, X / k - 1);
	LL lo = max(100001LL, X / (k+1));
	if (lo <= hi) {
	    ans += k * (hi - lo + 1);
	}
    }

    printf("%lld\n", ans);
    // slow(X, Y);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}