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

const int mod=1e9+7;
const int maxn=5e2+5;

int n,m;
char str[maxn][maxn];
int dp[2][maxn][maxn];

void add(int &a,int b){(a+=b)%=mod;}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	int cur=0;
	dp[0][1][n]=str[1][1]==str[n][m];
	int tot=n+m-2>>1;
	for(int i=1;i<=tot;i++){
		memset(dp[1-cur],0,sizeof(dp[1-cur]));
		for(int j=1;j<=n&&j-1<=i;j++)for(int k=n;k>=j&&n-k<=i;k--){
			if(1+(i-(j-1))<1)continue;
			if(m-(1-(n-k))<1)continue;
			char a=str[j][1+(i-(j-1))],b=str[k][m-(i-(n-k))];
			if(a!=b)continue;
			add(dp[1-cur][j][k],dp[cur][j][k]);
			add(dp[1-cur][j][k],dp[cur][j-1][k]);
			add(dp[1-cur][j][k],dp[cur][j][k+1]);
			add(dp[1-cur][j][k],dp[cur][j-1][k+1]);
		}
		cur=1-cur;
	}
	int ans=0;
	for(int i=1;i<=n;i++)add(ans,dp[cur][i][i]);
	if((n+m)%2)for(int i=1;i<n;i++)add(ans,dp[cur][i][i+1]);
	printf("%d\n",ans);
	return 0;
}