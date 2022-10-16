#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int llint;


const int N = 2005;
const int MOD = 1e9 + 7;

int dp[N][N],n,m,gt[N][N][2];

inline int f(int w,int h){
	return dp[w][h];
}

void do_dp2(){
	for(int i = 1;i<N;i++){
		dp[i][1] = 1;dp[i][0] = 0;
		dp[2][i] = 1;
	}
	for(int j = 2;j<N;j++){
		int sum = dp[2][j-1],reg = dp[2][j-1];
		for(int i = 3;i<N;i++){
			reg = (reg + dp[i][j-1]) % MOD;
			sum = (sum + reg) % MOD;
			dp[i][j] = sum;
		}
	}
}

int get(int x, int y, int lim){
	return (f(x, y ) -  lim * f(x, y -1 ) + MOD) % MOD;
}

int main(){
	memset(dp,-1,sizeof(dp));
	do_dp2();
	scanf("%d%d",&n,&m);
	llint sol = 0;
	for(int i = 1;i<N;i++){
        for(int j = 1;j<N;j++){
            gt[i][j][0] = (get(i,j,0) + gt[i][j-1][0]) % MOD;
            gt[i][j][1] = (get(i,j,1) + gt[i][j-1][1]) % MOD;
        }
	}
	for(int i = 0;i<n;i++){
		for(int d = 2;d<=m;d++){
			llint sum1 = gt[d][i+1][1],sum2 = gt[d][n-i][0];
			sol  = (sum1 * sum2 % MOD* (m - d + 1) % MOD + sol) % MOD;
		}
	}
	printf("%d\n",sol);
}