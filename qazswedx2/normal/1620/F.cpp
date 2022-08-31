#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,p[1000005],dp[1000005][2],g[1000005][2],tans[1000005];
void upd(int &ans,int &ans2,int x,int u,int v,int fl)
{
	if(u>v) swap(u,v);
	if(x>=v)
	{
		if(u<ans)
		{
			ans=u;
			ans2=fl;
		}
	}
	else if(x>=u)
	{
		if(v<ans)
		{
			ans=v;
			ans2=fl;
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		dp[1][0]=dp[1][1]=-1e9;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=dp[i][1]=1e9;
			upd(dp[i][0],g[i][0],-p[i],-p[i-1],dp[i-1][0],0);
			upd(dp[i][0],g[i][0],-p[i],p[i-1],dp[i-1][1],1);
			upd(dp[i][1],g[i][1],p[i],-p[i-1],dp[i-1][0],0);
			upd(dp[i][1],g[i][1],p[i],p[i-1],dp[i-1][1],1);
		//	printf("i=%d,dp=%d,%d\n",i,dp[i][0],dp[i][1]);
		}
		if(dp[n][1]>1e8)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int fl=1;
		for(int i=n;i>0;i--)
		{
			tans[i]=p[i]*(fl*2-1);
			fl=g[i][fl];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",tans[i]); 
		printf("\n");
	}
	return 0;
}