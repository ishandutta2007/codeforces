//sol rng_58 
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
#define N 5010
using namespace std;
ll n,m,vf[N];
bool ds[N],dt[N];
vector<ll> vt[N],bk[N];
vector<pair<ll,ll> > ed;
void dfs(ll x)
{
	ll i;
	ds[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(!ds[vt[x][i]])
		{
			dfs(vt[x][i]);
		}
	}
	return;
}
void dfs2(ll x)
{
	ll i;
	dt[x]=true;
	for(i=0;i<bk[x].size();i++)
	{
		if(!dt[bk[x][i]])
		{
			dfs2(bk[x][i]);
		}
	}
	return;
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		ed.push_back(make_pair(x,y));
		vt[x].push_back(y);
		bk[y].push_back(x);
	}
	memset(ds,false,sizeof(ds));
	dfs(0);
	memset(dt,false,sizeof(dt));
	dfs2(n-1);
	/*
	
	n,m
	nn
	
	(n) 
	*/
	memset(vf,127,sizeof(vf));
	vf[0]=0;
	for(j=0;j<=n;j++)
	{
		for(i=0;i<ed.size();i++)
		{
			if(ds[ed[i].F]&&dt[ed[i].S])
			{
				x=vf[ed[i].S];
				y=vf[ed[i].F];
				vf[ed[i].S]=min(vf[ed[i].S],y+2);
				vf[ed[i].F]=min(vf[ed[i].F],x-1);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(ds[ed[i].F]&&dt[ed[i].S])
		{
			if(abs(vf[ed[i].S]-vf[ed[i].F])!=1&&abs(vf[ed[i].S]-vf[ed[i].F])!=2)
			{
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	for(i=0;i<ed.size();i++)
	{
		if((!ds[ed[i].F])||(!dt[ed[i].S]))
		{
			puts("1");
		}
		else
		{
			printf("%lld\n",abs(vf[ed[i].S]-vf[ed[i].F]));
		}
	}
	return 0;
}