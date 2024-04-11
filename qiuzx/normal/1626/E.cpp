//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,col[N],sz[N],par[N],s[N],f[N][20],g[N][20];
vector<ll> vt[N];
void predfs(ll x,ll lst)
{
	ll i;
	par[x]=lst;
	sz[x]=col[x];
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			if(col[vt[x][i]])
			{
				s[x]=1;
			}
			predfs(vt[x][i],x);
			if(s[vt[x][i]])
			{
				s[x]=1;
			}
			sz[x]+=sz[vt[x][i]];
		}
	}
	if(sz[x]<2)
	{
		s[x]=0;
	}
	return;
}
void dfs(ll x,ll lst)
{
	ll i;
	g[x][0]=s[x];
	for(i=1;i<20;i++)
	{
		if(f[x][i-1]==-1)
		{
			break;
		}
		f[x][i]=f[f[x][i-1]][i-1];
		g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1];
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			f[vt[x][i]][0]=x;
			dfs(vt[x][i],x);
		}
	}
	return;
}
int main(){
	ll i,j,x,y,tot=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&col[i]);
		tot+=col[i];
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	predfs(0,-1);
	for(i=0;i<n;i++)
	{
		if(col[i])
		{
			s[i]=1;
		}
		for(j=0;j<vt[i].size();j++)
		{
			if(col[vt[i][j]]&&vt[i][j]!=par[i])
			{
				s[i]=1;
			}
		}
	}
	memset(f,-1,sizeof(f));
	dfs(0,-1);
	for(i=0;i<n;i++)
	{
		if(par[i]!=-1&&col[par[i]]==1)
		{
			printf("1 ");
			continue;
		}
		x=i,y=0;
		for(j=19;j>=0;j--)
		{
			if(f[x][j]==-1)
			{
				continue;
			}
			if(tot-sz[f[x][j]]>=2)
			{
				y+=g[x][j];
				x=f[x][j];
			}
		}
		y+=s[x];
		if(tot-sz[x]>=2)
		{
			if(par[x]!=-1)
			{
				x=par[x];
				y+=s[x];
				if(par[x]!=-1)
				{
					x=par[x];
					y+=col[x];
				}
			}
		}
		else if(tot-sz[x]==1)
		{
			if(par[x]!=-1)
			{
				y+=col[par[x]];
			}
		}
		printf("%lld ",(y>=1));
	}
	return 0;
}
/*
9
1 0 0 0 0 0 0 0 1
1 2
2 3
3 4
4 5
5 6
2 7
7 8
8 9
*/