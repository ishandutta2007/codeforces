#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL B, Bd, Bn;
LL C, Cd, Cn;

bool contains(LL x) {
    return (B <= x && (x - B) % Bd == 0 && (x - B) / Bd < Bn);
}

const LL MOD = 1000000007;
LL calc(LL Ad) {
    LL g = gcd(Ad, Bd);

    if (Cd * g != Ad * Bd) return 0;

    LL m = (Cd+Ad-1) / Ad;
    return m * m % MOD;
}

LL solve() {
    if (Cd % Bd) return 0;

    if (!contains(C)) return 0;
    if (!contains(C + Cd * (Cn - 1))) return 0;

    if (!contains(C - Cd)) return -1;
    if (!contains(C + Cd * Cn)) return -1;

    LL ret = 0;
    for (LL d=1; d*d<=Cd; d++) if (Cd % d == 0) {
	ret += calc(d);
	if (d * d < Cd) ret += calc(Cd / d);
    }
    return ret % MOD;
}

void MAIN() {
    scanf("%lld%lld%lld%lld%lld%lld", &B, &Bd, &Bn, &C, &Cd, &Cn);

    LL ans = solve();
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}