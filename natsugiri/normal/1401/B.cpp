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

LL A[3];
LL B[3];

void MAIN() {
    REP (i, 3) scanf("%lld", A+i);
    REP (i, 3) scanf("%lld", B+i);

    LL ans = 0;
    LL g = min(A[2], B[1]);
    ans += g*2;
    A[2] -= g;
    B[1] -= g;

    REP (i, 3) {
	if (i != 2) {
	    g = min(A[1], B[i]);
	    A[1] -= g;
	    B[i] -= g;
	}
	if (i != 1) {
	    g = min(A[i], B[2]);
	    A[i] -= g;
	    B[2] -= g;
	}
    }

    assert(A[1] == B[2]);
    ans -= A[1] * 2;

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}