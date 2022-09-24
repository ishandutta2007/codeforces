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
int dp[1<<17][2];

void PUSH(int v, int i) {
    if (dp[v][1] < i) swap(dp[v][1], i);
    if (dp[v][0] < i) swap(dp[v][0], i);
}


void MAIN() {
    scanf("%d%d", &N, &K);
    int m = 0;
    int sz = 1;
    while (sz <= N) {
	sz += sz;
	m++;
    }
    REP (i, sz) dp[i][0] = dp[i][1] = -1;

    REP (i, N) {
	int x;
	scanf("%d", &x);
	PUSH(x, i+1);
    }

    // eprintf("%d %d\n", m, sz);
    REP (t, m) REP (i, sz) if (~i>>t&1) {
        PUSH(i|(1<<t), dp[i][0]);
        PUSH(i|(1<<t), dp[i][1]);
    }

    LL ans = -(1LL<<60);
    REP (i, sz) if (dp[i][0] != -1 && dp[i][1] != -1) {
	LL tmp = (LL)dp[i][0] * dp[i][1] - (LL)K * i;
	amax(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}