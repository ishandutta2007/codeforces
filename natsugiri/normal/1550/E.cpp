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
char S[200011];
int sums[200011][18];

int nxt[200011][17];
int dp[1<<17];

bool ok(int mid) {
    REP (t, K) nxt[N][t] = 1<<29;

    for (int i=N; i--;) {
	REP (t, K) nxt[i][t] = nxt[i+1][t];

	if (i+mid <= N) {
	    int q = sums[i+mid][K] - sums[i][K];

	    REP (t, K) {
		if (sums[i+mid][t] - sums[i][t] + q == mid) {
		    nxt[i][t] = i;
		}
	    }
	}
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    REP (s, 1<<K) if (dp[s] <= N) {
	REP (t, K) if (~s>>t&1) {
	    if (nxt[dp[s]][t] < N) {
		amin(dp[s | (1<<t)], nxt[dp[s]][t] + mid);
	    }
	}
    }

    return dp[(1<<K)-1] <= N;
}

void MAIN() {
    scanf("%d%d%s", &N, &K, S);

    REP (i, N) {
	REP (t, K+1) sums[i+1][t] = sums[i][t];
	if (S[i] == '?') sums[i+1][K]++;
	else sums[i+1][S[i]-'a']++;
    }

    int lo = 0, hi = 1;
    while (ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    printf("%d\n", lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}