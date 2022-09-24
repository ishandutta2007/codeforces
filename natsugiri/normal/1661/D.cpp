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

int N;
int K;
LL B[300011];

LL X[300011];
LL Y[300011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lld", B+i+1);

    LL ans = 0;

    for (int i=N; i>=1; i--) {
	// B[i-K+1] ... B[i];
	
	if (i >= K && X[i] < B[i]) {
	    LL g = (B[i] - X[i] + K - 1) / K;
	    ans += g;
	    X[i] += K * g;
	    Y[i] += -g;
	    Y[i-K] += g;
	}

	X[i-1] += X[i] + Y[i];
	Y[i-1] += Y[i];
    }

    // rprintf("%lld", X, X+N+1);
    // rprintf("%lld", Y, Y+N+1);

    LL ma = 0;
    for (int i=1; i<=K; i++) {
	if (X[i] < B[i]) {
	    amax(ma, (B[i] - X[i] + i - 1) / i);
	}
    }

    ans += ma;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}