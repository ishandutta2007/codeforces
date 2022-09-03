#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;

const int maxn=511;
char s[maxn];
int dp[maxn][maxn],n;
int main()
{
	scanf("%d%s",&n,s+1);
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=1;
	for(int i=0;i<=n;i++)dp[i+1][i]=0;
	for(int l=2;l<=n;l++)for(int i=1;i+l-1<=n;i++)
	{
		int j=i+l-1;
		for(int k=i+1;k<=j;k++)
		{
			dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]);
			if(s[i]==s[k])dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}