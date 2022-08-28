#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[500005],c[500005][2],f[500005],dp[500005],vis[500005],sum[500005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum[a[i]]++;
		if(c[a[i]][0]==0) c[a[i]][0]=c[a[i]][1]=i;
		else c[a[i]][1]=i;
	}
	for(int i=1;i<=n;i++)
		if(c[i][0]) f[c[i][1]]=c[i][0];
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(f[i]) dp[i]=max(dp[i],dp[f[i]-1]+sum[a[i]]);
	}
	int mx=0,ans=0;
	for(int i=n;i>0;i--)
	{
		ans=max(ans,mx+dp[i]);
		vis[a[i]]++;
		if(vis[a[i]]>mx) mx=vis[a[i]];
	}
	printf("%d\n",n-ans);
	return 0;
}