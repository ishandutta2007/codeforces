#include <cstdio>
#include <algorithm>
using namespace std;
long long bit_array[400010],tree[1200010],lazy[1200010];
int n,q,a[400010],b[400010],c[400010],opt,x,y,to_root[200010],num,tot,head[200010],to[200010],nxt[200010],size[200010],dfn[200010][2],dfx[400010];
inline int lowbit(int x){return x&(-x);}
void modify(int x,int y){for(;x<=2*n;x+=lowbit(x))bit_array[x]+=y;}
long long get(int x){long long s=0;for(;x;x-=lowbit(x))s+=bit_array[x];return s;}
void build(int p,int le,int ri)
{
	if(le==ri)
	{
		tree[p]=to_root[dfx[le]];
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	tree[p]=min(tree[p<<1],tree[p<<1|1]);
}
void modify(int p,int le,int ri,int ll,int rr,int x)
{
	if(le==ll&&ri==rr)
	{
		tree[p]+=x;
		lazy[p]+=x;
		return;
	}
	if(lazy[p])
	{
		tree[p<<1]+=lazy[p];
		lazy[p<<1]+=lazy[p];
		tree[p<<1|1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
	int mid=(le+ri)>>1;
	if(rr<=mid)
		modify(p<<1,le,mid,ll,rr,x);
	else if(ll>mid)
		modify(p<<1|1,mid+1,ri,ll,rr,x);
	else
	{
		modify(p<<1,le,mid,ll,mid,x);
		modify(p<<1|1,mid+1,ri,mid+1,rr,x);
	}
	tree[p]=min(tree[p<<1],tree[p<<1|1]);
}
long long query(int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
		return tree[p];
	if(lazy[p])
	{
		tree[p<<1]+=lazy[p];
		lazy[p<<1]+=lazy[p];
		tree[p<<1|1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
	int mid=(le+ri)>>1;
	if(rr<=mid)
		return query(p<<1,le,mid,ll,rr);
	else if(ll>mid)
		return query(p<<1|1,mid+1,ri,ll,rr);
	else
		return min(query(p<<1,le,mid,ll,mid),query(p<<1|1,mid+1,ri,mid+1,rr));

}
void add(int x,int y,int z)
{
	nxt[++num]=head[x];
	to[head[x]=num]=y;
	size[num]=z;
}
void dfs(int p)
{
	dfx[dfn[p][0]=++tot]=p;
	for(int i=head[p];i;i=nxt[i])
		dfs(to[i]);
	dfx[dfn[p][1]=++tot]=p;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=2*n-2;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<n;i++)
		add(a[i],b[i],c[i]);
	dfs(1);
	for(int i=n;i<2*n-1;i++)
		to_root[a[i]]=c[i];
	build(1,1,2*n);
	for(int i=1;i<n;i++)
	{
		modify(dfn[b[i]][0],c[i]);
		modify(dfn[b[i]][1],-c[i]);
		modify(1,1,2*n,dfn[b[i]][0],dfn[b[i]][1],c[i]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
		{
			if(x<n)
			{
				modify(dfn[b[x]][0],y-c[x]);
				modify(dfn[b[x]][1],c[x]-y);
				modify(1,1,2*n,dfn[b[x]][0],dfn[b[x]][1],y-c[x]);
				c[x]=y;
			}
			else
			{
				modify(1,1,2*n,dfn[a[x]][0],dfn[a[x]][0],y-to_root[a[x]]);
				modify(1,1,2*n,dfn[a[x]][1],dfn[a[x]][1],y-to_root[a[x]]);
				to_root[a[x]]=y;
			}
		}
		else
		{
			if(x==y)
				printf("0\n");
			else if(dfn[x][0]<dfn[y][0]&&dfn[y][0]<dfn[x][1])
				printf("%I64d\n",get(dfn[y][0])-get(dfn[x][0]));
			else
				printf("%I64d\n",query(1,1,2*n,dfn[x][0],dfn[x][1])-get(dfn[x][0])+get(dfn[y][0]));
		}
	}
	return 0;
}