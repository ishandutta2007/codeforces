#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define popcount __builtin_popcount
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()
#define max3(a,b,c) max((a), max((b),(c)))

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int INF = 1000*1000*1000;

int n, k;
int min_suf, max_suf;
int res;
int seq[30010];
int dp[4][30010][203];

/*
	0 1 2 3 0
	    ^
	  /   \
	v       v
*/

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,1,n+1) scanf("%d", &seq[i]);
	FWD(d,0,4) FWD(i,0,n+1) FWD(r,0,k+1) dp[d][i][r] = -INF;
	min_suf = INF, max_suf = -INF;
	FWD(i,1,n+1){
		int a = seq[i];
		min_suf = min(a, min_suf+a);
		max_suf = max(a, max_suf+a);
		dp[0][i][1] = -min_suf;
		dp[2][i][1] = max_suf;
		FWD(r,2,k+1){
			dp[0][i][r] = max3(dp[0][i-1][r], dp[2][i-1][r-1], dp[3][i-1][r-1]) - 2*a;
			dp[1][i][r] = max3(dp[1][i-1][r], dp[0][i-1][r-1], dp[1][i-1][r-1]);
			dp[2][i][r] = max3(dp[2][i-1][r], dp[0][i-1][r-1], dp[1][i-1][r-1]) + 2*a;
			dp[3][i][r] = max3(dp[3][i-1][r], dp[2][i-1][r-1], dp[3][i-1][r-1]);
		}
	}
	max_suf = -INF, min_suf = INF;
	BCK(i,n,0){
		int a = seq[i];
		min_suf = min(a, min_suf+a);
		max_suf = max(a, max_suf+a);
		res = max(res, max(dp[2][i-1][k-1], dp[3][i-1][k-1]) - min_suf);
		res = max(res, max(dp[0][i-1][k-1], dp[1][i-1][k-1]) + max_suf);
	}
	printf("%d\n", res);
	return 0;
}