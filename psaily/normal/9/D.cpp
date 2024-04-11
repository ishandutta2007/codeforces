#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=36;

ll C[100][100];

void pre(){
	C[0][0]=1;
	for(int i=1;i<100;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}

int n,h;
ll ans;
ll dp[maxn][maxn][maxn];

int main(){
	pre();
	scanf("%d%d",&n,&h);
	dp[1][1][1]=1;
	for(int i=1;i<n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(dp[i][j][k]){
		//printf("dp[%d][%d][%d]=%lld\n",i,j,k,dp[i][j][k]);
		for(int p=1;p<=2*k&&j+p<=n;p++)dp[i+1][j+p][p]+=dp[i][j][k]*C[2*k][p];
	}
	for(int i=h;i<=n;i++)for(int k=1;k<=n;k++)ans+=dp[i][n][k];
	printf("%lld\n",ans);
	return 0;
}