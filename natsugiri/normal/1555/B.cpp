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

const LL INF = 1LL<<60;
LL W, H;
LL X0, Y0;
LL X1, Y1;
LL ww, hh;

void MAIN() {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &W, &H, &X0, &Y0, &X1, &Y1, &ww, &hh);

    LL ans = INF;
    if (ww + (X1 - X0) <= W) {
	if (ww <= X0) amin(ans, 0LL);
	else amin(ans, ww - X0);

	if (X1 + ww <= W) amin(ans, 0LL);
	else amin(ans, X1 + ww - W);
    }
    if (hh + (Y1 - Y0) <= H) {
	if (hh <= Y0) amin(ans, 0LL);
	else amin(ans, hh - Y0);

	if (Y1 + hh <= H) amin(ans, 0LL);
	else amin(ans, Y1 + hh - H);
    }


    if (ans == INF) {
	puts("-1");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}