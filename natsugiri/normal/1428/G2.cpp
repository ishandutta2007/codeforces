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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int K;


LL F[6];
int Q;

LL dp[1000011];

void MAIN() {
    scanf("%d", &K);
    REP (i, 6) scanf("%lld", F+i);

    VI Z;
    int m = 3 * (K-1), s = 1;
    while (s <= m) {
	Z.push_back(s);
	m -= s;
	s *= 2;
    }
    if (m) Z.push_back(m);

    memset(dp, 0xc0, sizeof dp);
    dp[0] = 0;

    LL TEN = 1;
    REP (t, 6) {
	EACH (e, Z) {
	    LL shift = 3 * TEN * *e;
	    for (int i=999999; i>0; i-=3) {
		if (shift <= i) {
		    amax(dp[i], dp[i - shift] + F[t] * *e);
		}
	    }
	}
	TEN *= 10;
    }

    TEN = 1;
    REP (t, 6) {
	for (int i=1000000; i>0; i--) {
	    for (int d=1; d<=9; d++) {
		LL ad = 0;
		if (d % 3 == 0) ad = d / 3 * F[t];
		LL shift = TEN * d;
		if (shift <= i) {
		    amax(dp[i], dp[i - shift] + ad);
		}
	    }
	}
	TEN *= 10;
    }

    // rprintf("%lld", dp, dp+100);


    scanf("%d", &Q);
    REP ($, Q) {
	int x;
	scanf("%d", &x);

	LL ans = dp[x];
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
    //    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}