#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
#define pb(x) push_back(x)
vector<int> g[100010];
long long tree[400010],lazy[400010];
int deep[100010],par[22][100010],dfn[100010],last[100010],a[100010],b[100010],root,n,q,ti,opt;
void dfs(int p,int fa)
{
	for(int i=1;i<=20;i++)
	{
		par[i][p]=par[i-1][par[i-1][p]];
	}
	dfn[p]=++ti;
	b[ti]=a[p];
	for(auto i:g[p])
	{
		if(i!=fa)
		{
			deep[i]=deep[p]+1;
			par[0][i]=p;
			dfs(i,p);
		}
	}
	last[p]=ti;
}
int lca(int x,int y)
{
	if(deep[x]>deep[y])
	{
		swap(x,y);
	}
	if(deep[x]<deep[y])
	{
		for(int i=20;i>=0;i--)
		{
			if(deep[par[i][y]]>=deep[x])
			{
				y=par[i][y];
			}
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=20;i>=0;i--)
	{
		if(par[i][x]!=par[i][y])
		{
			x=par[i][x];
			y=par[i][y];
		}
	}
	return par[0][x];
}
int get(int x,int dep)
{
	for(int i=20;i>=0;i--)
	{
		if(deep[par[i][x]]>=dep)
		{
			x=par[i][x];
		}
	}
	return x;
}
void build(int p,int le,int ri)
{
	if(le==ri)
	{
		tree[p]=b[le];
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
void modify(int p,int le,int ri,int ll,int rr,int x)
{
	if(le==ll&&ri==rr)
	{
		lazy[p]+=x;
		tree[p]+=1ll*(ri-le+1)*x;
		return;
	}
	int mid=(le+ri)>>1;
	if(lazy[p])
	{
		lazy[p<<1]+=lazy[p];tree[p<<1]+=1ll*(mid-le+1)*lazy[p];
		lazy[p<<1|1]+=lazy[p];tree[p<<1|1]+=1ll*(ri-mid)*lazy[p];
		lazy[p]=0;
	}
	if(rr<=mid)
	{
		modify(p<<1,le,mid,ll,rr,x);
	}
	else if(ll>mid)
	{
		modify(p<<1|1,mid+1,ri,ll,rr,x);
	}
	else
	{
		modify(p<<1,le,mid,ll,mid,x);
		modify(p<<1|1,mid+1,ri,mid+1,rr,x);
	}
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
long long get(int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
	{
		return tree[p];
	}
	int mid=(le+ri)>>1;
	if(lazy[p])
	{
		lazy[p<<1]+=lazy[p];tree[p<<1]+=1ll*(mid-le+1)*lazy[p];
		lazy[p<<1|1]+=lazy[p];tree[p<<1|1]+=1ll*(ri-mid)*lazy[p];
		lazy[p]=0;
	}
	if(rr<=mid)
	{
		return get(p<<1,le,mid,ll,rr);
	}
	else if(ll>mid)
	{
		return get(p<<1|1,mid+1,ri,ll,rr);
	}
	else
	{
		return get(p<<1,le,mid,ll,mid)+get(p<<1|1,mid+1,ri,mid+1,rr);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(deep[1]=1,0);
	root=1;
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&root);
		}
		else if(opt==2)
		{
			int u,v,x;
			scanf("%d%d%d",&u,&v,&x);
			int z=lca(u,v);
			if(dfn[z]<=dfn[root]&&dfn[root]<=last[z])
			{
				if((dfn[root]<=dfn[u]&&dfn[u]<=last[root])||(dfn[root]<=dfn[v]&&dfn[v]<=last[root]))
				{
					lazy[1]+=x;
					tree[1]+=1ll*n*x;
				}
				else
				{
					int p=lca(u,root);
					if(deep[p]>deep[z])
					{
						z=p;
					}
					p=lca(v,root);
					if(deep[p]>deep[z])
					{
						z=p;
					}
					p=get(root,deep[z]+1);
					lazy[1]+=x;
					tree[1]+=1ll*n*x;
					modify(1,1,n,dfn[p],last[p],-x);
				}
			}
			else
			{
				modify(1,1,n,dfn[z],last[z],x);
			}
		}
		else
		{
			int v;
			scanf("%d",&v);
			if(dfn[v]<=dfn[root]&&dfn[root]<=last[v])
			{
				if(root==v)
				{
					printf("%lld\n",tree[1]);
				}
				else
				{
					int u=get(root,deep[v]+1);
					printf("%lld\n",tree[1]-get(1,1,n,dfn[u],last[u]));
				}
			}
			else
			{
				printf("%lld\n",get(1,1,n,dfn[v],last[v]));
			}
		}
	}
	return 0;
}