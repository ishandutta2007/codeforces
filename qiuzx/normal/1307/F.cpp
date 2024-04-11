#pragma GCC optimize(2)
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
#define N 500010
using namespace std;
ll n,k,r,f[N][28],dist[N],fa[N],dep[N];
vector<ll> vt[N];
queue<ll> q;
ll getf(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
void dsu_mer(ll x,ll y)//y->x
{
	x=getf(x);
	y=getf(y);
	if(x==y)
	{
		return;
	}
	fa[y]=x;
	return;
}
void dfs(ll x,ll lst,ll d)
{
	dep[x]=d;
	ll i;
	if(lst!=-1)
	{
		for(i=1;i<26;i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
		}
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			f[vt[x][i]][0]=x;
			dfs(vt[x][i],x,d+1);
		}
	}
	return;
}
ll jump(ll x,ll len)
{
	ll i;
	for(i=0;i<26;i++)
	{
		if(len&(1<<i))
		{
			x=f[x][i];
		}
	}
	return x;
}
ll glca(ll x,ll y)
{
	ll i;
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	for(i=25;i>=0;i--)
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
    for(i=25;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
bool direc(ll s,ll t)//from s to t directly
{
	ll d=dep[s]+dep[t]-dep[glca(s,t)]*2;
	if(d<=2*k)
	{
		return true;
	}
	return false;
}
bool moving(ll s,ll t)//rest for some time
{
	ll s1,t1,lca=glca(s,t),d;
	d=dep[s]+dep[t]-dep[lca]*2;
	if(dep[s]-dep[lca]<k)
	{
		s1=jump(t,d-k);
	}
	else
	{
		s1=jump(s,k);
	}
	if(dep[t]-dep[lca]>=k)
	{
		t1=jump(t,k);
	}
	else
	{
		t1=jump(s,d-k);
	}
	if(getf(s1)==getf(t1))
	{
		return true;
	}
	return false;
}
int main(){
	ll i,qu,x,y;
	scanf("%lld%lld%lld",&n,&k,&r);
	for(i=0;i+1<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(n+i);
		vt[n+i].push_back(x);
		vt[y].push_back(n+i);
		vt[n+i].push_back(y);
	}
	for(i=0;i<2*n;i++)
	{
		fa[i]=i;
	}
	memset(dist,63,sizeof(dist));
	for(i=0;i<r;i++)
	{
		scanf("%lld",&x);
		x--;
		dist[x]=0;
		q.push(x);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(dist[x]>=k)//can't move anymore
		{
			continue;
		}
		for(i=0;i<vt[x].size();i++)
		{
			if(dist[vt[x][i]]>dist[x]+1)
			{
				dist[vt[x][i]]=dist[x]+1;
				q.push(vt[x][i]);
			}
			dsu_mer(x,vt[x][i]);
		}
	}
	dfs(0,-1,0);
	scanf("%lld",&qu);
	while(qu--)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		if(direc(x,y)||moving(x,y))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}