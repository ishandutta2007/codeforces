#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 500010
using namespace std;
ll n,m,a[N],p[N],b[N],dp[N],dif[N],ans=0;
int main(){
	ll i,x,l,r;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&p[i]);
	}
	scanf("%I64d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%I64d",&b[i]);
	}
	memset(dif,0,sizeof(dif));
	for(i=0;i<n;i++)
	{
		x=lower_bound(b,b+m,a[i])-b;
		if(x==m)
		{
			dif[m]+=p[i];
		}
		else if(p[i]<0)
		{
			dif[x]+=p[i];
		}
	}
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(i=0;i<n;i++)
	{
		x=lower_bound(b,b+m,a[i])-b;
		if(x<m)
		{
			if(b[x]==a[i])
			{
				if(p[i]<0)
				{
					dp[x+1]=min(dp[x]+dif[x]-p[i],dp[x+1]);
				}
				else
				{
					dp[x+1]=min(dp[x]+dif[x],dp[x+1]);
				}
			}
			if(p[i]>0)
			{
				dif[x]+=p[i];
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		if(dp[i]>=LINF/2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%I64d\n",dp[m]+dif[m]);
	return 0;
}