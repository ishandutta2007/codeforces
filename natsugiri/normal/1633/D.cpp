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

const int LIMIT = 1000;
int cost[LIMIT+1];
void init() {
    for (int i=2; i<=LIMIT; i++) cost[i] = 1<<29;

    for (int i=1; i<=LIMIT; i++) {
	for (int j=i; j>=1; j--) {
	    int m = i + i/j;
	    if (m > LIMIT) break;
	    amin(cost[m], cost[i] + 1);
	}
    }

}

int N, K;
int B[1011];
int C[1011];

LL dp[12011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", B+i);
    REP (i, N) scanf("%d", C+i);

    LL ans = 0;
    if (K >= N * 12) {
	REP (i, N) ans += C[i];
    } else {
	memset(dp, 0xc0, sizeof dp);
	dp[0] = 0;
	REP (i, N) {
	    for (int a=K-cost[B[i]]; a>=0; a--) {
		amax(dp[a+cost[B[i]]], dp[a] + C[i]);
	    }
	}

	ans = *max_element(dp, dp+K+1);
    }
    printf("%lld\n", ans);
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}