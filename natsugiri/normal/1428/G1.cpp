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


LL C[1<<20];
LL F[6];
int Q;

LL dp[7][1000011];

void MAIN() {
    scanf("%d", &K);
    REP (i, 6) scanf("%lld", F+i);

    int cnt = 0;
    REP (s, 1000000) {
	LL c = 0;
	int m = s;
	REP (t, 6) {
	    int x = m % 10;
	    m /= 10;
	    if (x == 3) c += F[t];
	    if (x == 6) c += F[t]*2;
	    if (x == 9) c += F[t]*3;
	}

	C[s] = c;
	if (c) cnt++;
    }


    scanf("%d", &Q);
    REP ($, Q) {
	int x;
	scanf("%d", &x);
	LL ans;

	if (K == 1) {
	    ans = C[x];
	} else {
	    memset(dp, 0xc0, sizeof dp);
	    dp[0][x] = 0;
	    int ONE = 1;
	    int TEN = 1;
	    REP (t, 6) {
		ONE = TEN;
		TEN *= 10;
		for (int a=0; a<=x; a+=ONE) if (dp[t][a] >= 0) {
		    int r = a % TEN;
		    for (int i=r; (LL)i <= a; i+=TEN) {
			int m = i / ONE;
			LL c = m / 9;
			LL d = m % 9;
			if (c + (d? 1: 0) > K) break;

			LL ad = F[t] * c * 3;
			if (d == 0) {

			} else if (K == c + 1) {
			    if (d % 3 == 0) ad += F[t] * (d / 3);
			} else {
			    ad += F[t] * (d / 3);
			}

			amax(dp[t+1][a - i], dp[t][a] + ad);
		    }
		}
	    }

	    ans = dp[6][0];
	}

	printf("%lld\n", ans);

    }
}

int main() {
    int TC = 1;
    //    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}