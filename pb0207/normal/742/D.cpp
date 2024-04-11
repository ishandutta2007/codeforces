#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const ll N=1e5+1e3+7;

ll n,m,fa[N],w[N],b[N],v,f[2][N],vis[N],ism[N],ww[N],bb[N];

vector<ll>g[1001];

ll find(ll x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d%d%d",&n,&m,&v);
	for(ll i=1;i<=n;i++)
		scanf("%d",&w[i]),fa[i]=i;
	for(ll i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v))
			fa[find(u)]=find(v);
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(!vis[j]&&find(i)==find(j))
			{
				g[i].push_back(j);
				ww[i]+=w[j];
				bb[i]+=b[j];
				ism[i]=true;
				vis[j]=true;
			}
	ll cur=1,last=0;
	for(ll i=1;i<=n;i++)
	if(ism[i])
	{
		swap(cur,last);
		for(ll j=0;j<=v;j++)
			f[cur][j]=f[last][j];
		for(ll j=v;j>=ww[i];j--)
			f[cur][j]=max(f[cur][j],f[last][j-ww[i]]+bb[i]);
		for(ll k=0;k<g[i].size();k++)
		for(ll j=v;j>=w[g[i][k]];j--)
		{
			ll x=g[i][k];
			f[cur][j]=max(f[cur][j],f[last][j-w[x]]+b[x]);
		}
	}
	cout<<f[cur][v];
}