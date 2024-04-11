#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n,m,k,occupy=0,restrict[12][12],col[1020][1020],cge[12],ans=0;
void dfs(ll x,ll y,ll mx)
{
	ll i,j,l,tp=0,tem=1;
	if(x==n)
	{
		for(i=1;i<=k;i++)
		{
			if(cge[i]!=0)
			{
				tp++;
			}
		}
		if(mx<=tp)
		{
			return;
		}
		for(i=1;i<mx-tp;i++)
		{
			tem=(tem*(k-i+1-tp))%MOD;
		}
		ans=(ans+tem)%MOD;
		return;
	}
	restrict[x][y]=0;
	if(x>0)
	{
		restrict[x][y]|=restrict[x-1][y];
	}
	if(y>0)
	{
		restrict[x][y]|=restrict[x][y-1];
	}
	if(col[x][y]>0)
	{
		if(cge[col[x][y]]!=0)
		{
			if(restrict[x][y]&(1<<cge[col[x][y]]))
			{
				return;
			}
			restrict[x][y]|=(1<<cge[col[x][y]]);
			if(y==m-1)
			{
				dfs(x+1,0,max(mx,cge[col[x][y]]+1));
			}
			else
			{
				dfs(x,y+1,max(mx,cge[col[x][y]]+1));
			}
			restrict[x][y]^=(1<<cge[col[x][y]]);
			return;
		}
		for(i=1;i<=min(mx,k);i++)
		{
			if(restrict[x][y]&(1<<i))
			{
				continue;
			}
			if(occupy&(1<<i))
			{
				continue;
			}
			cge[col[x][y]]=i;
			occupy|=(1<<i);
			restrict[x][y]|=(1<<i);
			if(y==m-1)
			{
				dfs(x+1,0,max(mx,i+1));
			}
			else
			{
				dfs(x,y+1,max(mx,i+1));
			}
			restrict[x][y]^=(1<<i);
			occupy^=(1<<i);
		}
		cge[col[x][y]]=0;
		return;
	}
	for(i=1;i<=min(mx,k);i++)
	{
		if(restrict[x][y]&(1<<i))
		{
			continue;
		}
		restrict[x][y]|=(1<<i);
		if(y==m-1)
		{
			dfs(x+1,0,max(mx,i+1));
		}
		else
		{
			dfs(x,y+1,max(mx,i+1));
		}
		restrict[x][y]^=(1<<i);
	}
	return;
}
int main(){
	ll i,j;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&col[i][j]);
		}
	}
	if(n+m-1>k)
	{
		puts("0");
		return 0;
	}
	for(i=0;i<12;i++)
	{
		cge[i]=0;
	}
	dfs(0,0,1);
	printf("%lld\n",ans);
	return 0;
}