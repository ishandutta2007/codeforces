//DSU Solution
#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 100010
using namespace std;
ll n,m,q,fa[N],fa2[N],dep[N],f[N][25],par[N],sum[N];
bool vis[N],odd[N];
vector<ll> vt[N];
ll getf(ll x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
ll getf2(ll x)
{
	if(x==fa2[x])
	{
		return x;
	}
	return fa2[x]=getf2(fa2[x]);
}
void dfs(ll x,ll lst,ll d)
{
	vis[x]=true;
	par[x]=lst;
	dep[x]=d;
	ll i,j;
	for(i=0;i<22;i++)
	{
		f[x][i+1]=f[f[x][i]][i];
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			if(!vis[vt[x][i]])
			{
				f[vt[x][i]][0]=x;
				dfs(vt[x][i],x,d+1);
				if(odd[vt[x][i]]&&getf2(x)==getf2(vt[x][i]))
				{
					odd[x]=true;
				}
			}
			else
			{
				if(dep[vt[x][i]]<dep[x])//in a cycle
				{
					if((dep[x]-dep[vt[x][i]])%2==0)//in an odd cycle
					{
						odd[x]=true;
					}
					j=getf2(x);
					while(dep[j]>dep[vt[x][i]]+1)
					{
						fa2[j]=par[j];
						j=getf2(j);
					}
				}
			}
		}
	}
	return;
}
void dfs2(ll x,ll lst)
{
	vis[x]=true;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			if(odd[x]&&getf2(x)==getf2(vt[x][i]))
			{
				odd[vt[x][i]]=true;
			}
			dfs2(vt[x][i],x);
		}
	}
	return;
}
void dfs3(ll x,ll lst)
{
	vis[x]=true;
	sum[x]=odd[x];
	if(lst!=-1)
	{
		sum[x]+=sum[lst];
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs3(vt[x][i],x);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	ll i;
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	for(i=22;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
		if(x==y)
		{
			return x;
		}
	}
	for(i=22;i>=0;i--)
    {
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	ll i,j,x,y,a,b;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		fa[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		a=getf(x);
		b=getf(y);
		fa[b]=a;
	}
	for(i=0;i<n;i++)
	{
		fa[i]=getf(i);
		fa2[i]=i;
		odd[i]=false;
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1,0);
		}
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs2(i,-1);
		}
	}
	memset(vis,false,sizeof(vis));
	memset(sum,0,sizeof(sum));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs3(i,-1);
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		if(fa[x]!=fa[y]||x==y)
		{
			puts("No");
			continue;
		}
		a=glca(x,y);
		if((dep[x]+dep[y]-dep[a]*2)%2==1)
		{
			puts("Yes");
		}
		else if((sum[x]-sum[a])!=0)
		{
			puts("Yes");
		}
		else if((sum[y]-sum[a])!=0)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}