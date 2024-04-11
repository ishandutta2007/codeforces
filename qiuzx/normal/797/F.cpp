#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 5010
using namespace std;
ll n,m,dp[N][N],d[N],c[N],dist[N],val[14][N];
pair<ll,ll> p[N];
void update(ll st)
{
	ll i,j;
	for(i=0;i<=n;++i)
	{
		val[0][i]=dp[i][st]-dist[i];
	}
	for(i=0;i<13;++i)
	{
		for(j=n;j>=0;--j)
		{
			val[i+1][j]=min(val[i][j],val[i][j+(1<<i)]);
		}
	}
	return;
}
ll query(ll l,ll r)
{
	ll len=r-l+1,i,ret=LINF;
	for(i=13;i>=0;--i)
	{
		if(len&(1<<i))
		{
			ret=min(ret,val[i][l]);
			l+=(1<<i);
		}
	}
	return ret;
}
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&m);
	d[0]=-LINF;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&d[i]);
	}
	sort(d,d+n+1);
	for(i=0;i<m;++i)
	{
		scanf("%lld%lld",&p[i].F,&p[i].S);
	}
	sort(p,p+m);
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<m;++i)
	{
		dist[0]=0;
		for(j=1;j<=n;++j)
		{
			dist[j]=dist[j-1]+abs(d[j]-p[i].F);
		}
		update(i);
		for(j=0;j<=n;++j)
		{
			dp[j][i+1]=dist[j]+query(max((ll)0,j-p[i].S),j);
		}
	}
	if(dp[n][m]>=LINF)
	{
		puts("-1");
	}
	else
	{
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}