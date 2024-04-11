#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 100010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll n,m,fa[N],sz[N],dp[N],app[N],ans=INF;
bool is_lucky(ll x)
{
	while(x>0)
	{
		if(x%10!=4&&x%10!=7)
		{
			return false;
		}
		x/=10;
	}
	return true;
}
ll getf(ll x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
int main(){
	ll i,j,x,y;
	n=rint(),m=rint();
	for(i=0;i<n;i++)
	{
		fa[i]=i;
	}
	for(i=0;i<m;i++)
	{
		x=rint()-1,y=rint()-1;
		x=getf(x);
		y=getf(y);
		fa[x]=y;
	}
	for(i=0;i<n;i++)
	{
		x=getf(i);
		app[sz[x]]--;
		sz[x]++;
		app[sz[x]]++;
		dp[i]=INF*2;
	}
	dp[n]=INF*2;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;app[i]>0;j<<=1)
		{
			j=min(j,app[i]);
			app[i]-=j;
			for(x=n-j*i;x>=0;x--)
			{
				dp[x+j*i]=min(dp[x+j*i],dp[x]+j);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(is_lucky(i))
		{
			ans=min(ans,dp[i]);
		}
	}
	if(ans==INF)
	{
		ans=0;
	}
	printf("%d\n",ans-1);
	return 0;
}