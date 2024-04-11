#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=105;
const int mod=1e9+7;

int n,ans;
int cnt[11];
int dp[11][maxn];
int C[maxn][maxn];

void add(int &a,int b){(a+=b)%=mod;}

void pre(){
	C[0][0]=1;
	for(int i=1;i<maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}

int main(){
	pre();
	scanf("%d",&n);
	for(int i=0;i<=9;i++)scanf("%d",&cnt[i]);
	dp[10][0]=1;
	for(int i=9;i>=1;i--)for(int j=0;j<=n;j++){
		for(int k=cnt[i];k<=n;k++)if(j>=k)
			add(dp[i][j],1ll*dp[i+1][j-k]*C[j][k]%mod);
		//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	for(int i=0;i<=n;i++)for(int j=cnt[0];j<=n;j++)if(i>=j)
		add(dp[0][i],1ll*dp[1][i-j]*C[i-1][j]%mod);
	for(int i=0;i<=n;i++)add(ans,dp[0][i]);
	printf("%d\n",ans);
	return 0;
}