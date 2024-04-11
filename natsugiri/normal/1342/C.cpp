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

LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

LL A, B, Q;

void MAIN() {
    scanf("%lld%lld%lld", &A, &B, &Q);
    if (A > B) swap(A, B);
    LL D = lcm(A, B);
    vector<pair<int, int> > P;
    VI X;
    REP (r, D) {
	if (r % A % B != r % B % A) {
	    X.push_back(r);
	    if (P.empty() || P.back().second + 1 < r) P.emplace_back(r, r);
	    else P.back().second = r;
	}
    }
    //eprintf("%d\n", (int)X.size());
    //eprintf("%d\n", (int)P.size());
    //eprintf("%d %d\n", P[0].first, P[0].second);

    REP ($, Q) {
	LL L, R;
	scanf("%lld%lld", &L, &R);
	L--;
	LL ans = 0;
	
	if (A == 1 || B == 1 || A == B) {
	} else {
	    // B .. D-1;
	    auto F = [&](LL h) -> LL {
		LL ret = 0;
		ret += h / D * (D - B);
		h %= D;
		if (B <= h) ret += h - B + 1;
		return ret;
	    };
	    ans = F(R) - F(L);
	}
	printf("%lld%c", ans, " \n"[$==Q-1]);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}