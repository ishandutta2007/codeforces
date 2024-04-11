#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll n,m,dp[N][30],f[(1<<12)+10],ans;
vector<ll> vt1[N],vt2[N],id[N];
void dfs0(ll x,ll lst)
{
	ll i,j,k,l;
	for(i=0;i<vt1[x].size();i++)
	{
		if(vt1[x][i]!=lst)
		{
			dfs0(vt1[x][i],x);
		}
	}
	for(i=0;i<m;i++)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		for(j=0;j<vt1[x].size();j++)
		{
			if(vt1[x][j]==lst)
			{
				continue;
			}
			for(k=(1<<id[i].size())-1;k>=0;k--)
			{
				for(l=0;l<id[i].size();l++)
				{
					if(!(k&(1<<l)))
					{
						f[k|(1<<l)]=(f[k|(1<<l)]+f[k]*dp[vt1[x][j]][id[i][l]^1])%mod;
					}
				}
			}
		}
		ans=(ans+f[(1<<id[i].size())-1])%mod;
		for(j=0;j<id[i].size();j++)
		{
			dp[x][id[i][j]]=f[(1<<id[i].size())-1-(1<<j)];
		}
	}
	return;
}
void dfs1(ll x,ll lst)
{
	ll i,j,k,l;
	for(i=0;i<vt2[x].size();i++)
	{
		if(vt2[x][i]!=lst)
		{
			dfs1(vt2[x][i],x);
		}
	}
	for(i=0;i<m;i++)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		for(j=0;j<vt2[x].size();j++)
		{
			if(vt2[x][j]==lst)
			{
				continue;
			}
			for(k=(1<<id[i].size())-1;k>=0;k--)
			{
				for(l=0;l<id[i].size();l++)
				{
					if(!(k&(1<<l)))
					{
						f[k|(1<<l)]=(f[k|(1<<l)]+f[k]*dp[vt2[x][j]][id[i][l]^1])%mod;
					}
				}
			}
		}
		ans=(ans+f[(1<<id[i].size())-1])%mod;
		for(j=0;j<id[i].size();j++)
		{
			dp[x][id[i][j]]=f[(1<<id[i].size())-1-(1<<j)];
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt1[x].push_back(y);
		vt1[y].push_back(x);
	}
	scanf("%lld",&m);
	for(i=1;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt2[x].push_back(y);
		vt2[y].push_back(x);
		id[x].push_back(i<<1);
		id[y].push_back(i<<1|1);
	}
	memset(dp,0,sizeof(dp));
	ans=0;
	dfs0(0,-1);
	ll r1=ans;
	ans=0;
	dfs1(0,-1);
	ll r2=ksm(ans,mod-2);
	printf("%lld\n",(r1*r2)%mod);
	return 0;
}