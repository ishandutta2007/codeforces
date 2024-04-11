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



void MAIN() {
    LL X0, P0, X1, P1;
    scanf("%lld%lld%lld%lld", &X0, &P0, &X1, &P1);
    string S0 = to_string(X0);
    string S1 = to_string(X1);

    int d0 = S0.size() + P0;
    int d1 = S1.size() + P1;

    char ans = '=';

    if (d0 > d1) ans = '>';
    else if (d0 < d1) ans = '<';
    else {
	if (S0.size() < S1.size()) {
	    REP (t, S1.size() - S0.size()) X0 *= 10;
	} else {
	    REP (t, S0.size() - S1.size()) X1 *= 10;
	}

	if (X0 > X1) ans = '>';
	else if (X0 < X1) ans = '<';
	else ans = '=';
    }

    printf("%c\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}