#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[200005],f[200005],g[200005];
int st[200005],dp[200005],tp;
int main()
{
	scanf("%d",&n);
	int nw=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) nw=i;
	}
	int nans=0;
	tp=0;
	for(int i=nw,j=1;j<=n;i=i%n+1,j++)
	{
		while(tp&&a[st[tp]]>a[i])
		{
			dp[st[tp-1]]=max(dp[st[tp-1]],dp[st[tp]]+1);
			dp[i]=max(dp[i],dp[st[tp]]+1);
			tp--;
		}
	/*	printf("i=%d,dp=%d,tp=%d\n",i,dp[i],tp);
		for(int k=1;k<=tp;k++)
			printf("%d ",st[k]);
		printf("\n");*/
		nans=max(nans,dp[i]+tp);
		st[++tp]=i;
		f[j]=nans;
	}
	tp=nans=0;
	for(int i=nw,j=1;j<=n;i=(i==1?n:(i+n-1)%n),j++)
	{
		dp[i]=0;
		while(tp&&a[st[tp]]>a[i])
		{
			dp[st[tp-1]]=max(dp[st[tp-1]],dp[st[tp]]+1);
			dp[i]=max(dp[i],dp[st[tp]]+1);
			tp--;
		}
		nans=max(nans,dp[i]+tp);
		st[++tp]=i;
		g[j]=nans;
	}
/*	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",g[i]);
	printf("\n");*/
	int ans=1e9,id=0;
	for(int i=1,j=n;i<=n;i++,j--)
	{
		if(max(f[i],g[j])<ans)
		{
			ans=max(f[i],g[j]);
			id=i;
		//	printf("i=%d,j=%d,f=%d,g=%d\n",i,j,f[i],g[j]);
		}
	}
	id=(id+nw-1)%n;
	printf("%d %d\n",ans+1,id);
	return 0;
}