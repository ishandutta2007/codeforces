#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tree[55][140010],lazy[55][140010],f[35010][55],last[35010],pre[35010],a[35010],n,k;
void modify(int id,int p,int le,int ri,int x,int y)
{
	if(le==ri)
	{
		tree[id][p]=max(tree[id][p],y);
		return;
	}
	int mid=(le+ri)>>1;
	if(lazy[id][p])
	{
		lazy[id][p<<1]+=lazy[id][p];
		tree[id][p<<1]+=lazy[id][p];
		lazy[id][p<<1|1]+=lazy[id][p];
		tree[id][p<<1|1]+=lazy[id][p];
		lazy[id][p]=0;
	}
	if(x<=mid)
		modify(id,p<<1,le,mid,x,y);
	else
		modify(id,p<<1|1,mid+1,ri,x,y);
	tree[id][p]=max(tree[id][p<<1],tree[id][p<<1|1]);
}
void add(int id,int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
	{
		lazy[id][p]++;
		tree[id][p]++;
		return;
	}
	int mid=(le+ri)>>1;
	if(lazy[id][p])
	{
		lazy[id][p<<1]+=lazy[id][p];
		tree[id][p<<1]+=lazy[id][p];
		lazy[id][p<<1|1]+=lazy[id][p];
		tree[id][p<<1|1]+=lazy[id][p];
		lazy[id][p]=0;
	}
	if(rr<=mid)
		add(id,p<<1,le,mid,ll,rr);
	else if(ll>mid)
		add(id,p<<1|1,mid+1,ri,ll,rr);
	else
	{
		add(id,p<<1,le,mid,ll,mid);
		add(id,p<<1|1,mid+1,ri,mid+1,rr);
	}
	tree[id][p]=max(tree[id][p<<1],tree[id][p<<1|1]);
}
int query(int id,int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
		return tree[id][p];
	int mid=(le+ri)>>1;
	if(lazy[id][p])
	{
		lazy[id][p<<1]+=lazy[id][p];
		tree[id][p<<1]+=lazy[id][p];
		lazy[id][p<<1|1]+=lazy[id][p];
		tree[id][p<<1|1]+=lazy[id][p];
		lazy[id][p]=0;
	}
	if(rr<=mid)
		return query(id,p<<1,le,mid,ll,rr);
	else if(ll>mid)
		return query(id,p<<1|1,mid+1,ri,ll,rr);
	else
		return max(query(id,p<<1,le,mid,ll,mid),query(id,p<<1|1,mid+1,ri,mid+1,rr));
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
			add(j,1,0,n,pre[i],i-1);
		for(int j=1;j<=min(i,k);j++)
		{
			f[i][j]=query(j-1,1,0,n,0,i-1);
			if(j!=k)
				modify(j,1,0,n,i,f[i][j]);
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}