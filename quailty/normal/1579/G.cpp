#include <bits/stdc++.h>
using namespace std;
const int MAXL=2005;
const int INF=0x3f3f3f3f;
int dp[2][MAXL];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int now=0,la=1;
		for(int j=0;j<MAXL;j++)
			dp[now][j]=(j ? INF : 0);
		for(int i=1,a;i<=n;i++)
		{
			scanf("%d",&a);
			swap(now,la);
			for(int j=0;j<MAXL;j++)
				dp[now][j]=INF;
			for(int j=0;j<MAXL;j++)
			{
				if(j+a<MAXL)dp[now][j+a]=min(dp[now][j+a],max(dp[la][j],j+a));
				dp[now][max(j-a,0)]=min(dp[now][max(j-a,0)],dp[la][j]+max(a-j,0));
			}
		}
		int res=INF;
		for(int j=0;j<MAXL;j++)
			res=min(res,dp[now][j]);
		printf("%d\n",res);
	}
	return 0;
}