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
LL gcd(LL x, LL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL M, D, W;

void MAIN() {
    scanf("%lld%lld%lld", &M, &D, &W);
    // 0 <= x < y < min(M, D);
    // (x * D + y) % W == (y * D + x) % W;

    // 0 <= x < y < min(M, D);
    // y = x + k;
    // k % W == kD % W;
    // k(D - 1) == 0;

    LL ans = 0;
    if (M == 1 || D == 1) {
	ans = 0;
    } else {
	LL g = gcd(W, D-1);
	LL step = W / g;
	LL LIMIT = min(M, D) - 1;
	LL B = LIMIT / step;
	ans += B * (B-1) / 2 * step;
	ans += B * (LIMIT - B * step + 1);

	//for (LL x=1; x<=LIMIT; x++) {
	//    ans += x / step;
	//}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}