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
    LL A, B, C, D;
    LL X, Y, X1, Y1, X2, Y2;
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    scanf("%lld%lld%lld%lld%lld%lld", &X, &Y, &X1, &Y1, &X2, &Y2);

    bool yes = true;
    if (A|B) {
	if (X1 == X2) yes = false;
	else {
	    LL g = min(A, B);
	    A -= g;
	    B -= g;
	    if (X-A < X1) yes = false;
	    if (X2 < X+B) yes = false;
	}
    }
    if (C|D) {
	if (Y1 == Y2) yes = false;
	else {
	    LL g = min(C, D);
	    C -= g;
	    D -= g;
	    if (Y-C < Y1) yes = false;
	    if (Y2 < Y+D) yes = false;
	}
    }
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}