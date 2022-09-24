#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, K, M;
int A[111];
LL P[101][101];
LL dp[103][103][103];
LL INF;

int main() {

    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, N) REP (j, M) scanf("%lld", P[i]+j);

    memset(dp, 0x3f, sizeof dp);
    INF = dp[0][0][0];

    if (A[0] == -1) {
	REP (j, M) dp[1][j][1] = P[0][j];
    } else {
	dp[1][A[0]][1] = 0;
    }

    for (int i=1; i<N; i++) {
	REP (j, M) REP (k, K+1) if (dp[i][j][k] < INF) {
	    if (A[i] == -1) {
		REP (x, M) {
		    if (x == j) amin(dp[i+1][x][k], dp[i][j][k] + P[i][x]);
		    else amin(dp[i+1][x][k+1], dp[i][j][k] + P[i][x]);
		}
	    } else {
		if (A[i] == j) amin(dp[i+1][A[i]][k], dp[i][j][k]);
		else amin(dp[i+1][A[i]][k+1], dp[i][j][k]);
	    }
	}
    }


    LL ans = INF;
    REP (j, M) amin(ans, dp[N][j][K]);
    
    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);


    return 0;
}