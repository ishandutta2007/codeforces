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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[111];
int B[111];

int dp[111][10011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, B+i);

    int a_sum = 0;
    int b_sum = 0;
    REP (i, N) {
	b_sum += B[i];
    }

    memset(dp, 0xc0, sizeof dp);
    dp[0][0] = 0;
    REP (i, N) {
	for (int j=i; j>=0; j--) REP (a, a_sum+1) if (dp[j][a] >= 0) {
	    amax(dp[j+1][a + A[i]], dp[j][a] + B[i]);
	}
	a_sum += A[i];
    }

    for (int k=1; k<=N; k++) {
	double ans = 0;
	REP (a, a_sum+1) if (dp[k][a] >= 0) {
	    int x = b_sum - dp[k][a];
	    double tmp = min((double)a, dp[k][a] + x / 2.0);
	    amax(ans, tmp);
	}
	printf("%.12f%c", ans, " \n"[k==N]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}