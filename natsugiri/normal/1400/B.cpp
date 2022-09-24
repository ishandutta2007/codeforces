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


void MAIN() {
    LL P, F;
    LL CS, CW;
    LL S, W;
    scanf("%lld%lld%lld%lld%lld%lld", &P, &F, &CS, &CW, &S, &W);


    LL ans = 0;

    REP (t, 2) {
	REP (s0, CS+1) {
	    if (S * s0 > P) break;
	    LL s1 = min(CS - s0, F / S);
	    LL w0 = min(CW, (P - S * s0) / W);
	    LL w1 = min(CW - w0, (F - S * s1) / W);
	    amax(ans, s0 + s1 + w0 + w1);
	}
	if (S > W) {
	    swap(S, W);
	    swap(CS, CW);
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