#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,x,a[100010],tree[400010],lazy[400010],last,b[100010],tot,ans;
void build(int p,int le,int ri)
{
	if(le==ri)
	{
		tree[p]=a[le];
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	tree[p]=max(tree[p<<1],tree[p<<1|1]);
}
void modify(int p,int le,int ri,int ll,int rr,int x)
{
	if(le==ll&&ri==rr)
	{
		lazy[p]+=x;
		tree[p]+=x;
		return;
	}
	if(lazy[p])
	{
		lazy[p<<1]+=lazy[p];tree[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];tree[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
	int mid=(le+ri)>>1;
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
	tree[p]=max(tree[p<<1],tree[p<<1|1]);
}
int get(int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
	{
		return tree[p];
	}
	if(lazy[p])
	{
		lazy[p<<1]+=lazy[p];tree[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];tree[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
	int mid=(le+ri)>>1;
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
		return max(get(p<<1,le,mid,ll,mid),get(p<<1|1,mid+1,ri,mid+1,rr));
	}
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=a[i-1]+x;
		if(x==0)
		{
			b[++tot]=i;
		}
	}
	build(1,1,n);
	if(get(1,1,n,1,n)>d)
	{
		puts("-1");
		return 0;
	}
	last=0;ans=0;
	for(int i=1;i<=tot;i++)
	{
		int x=get(1,1,n,b[i],b[i]);
		if(x<0)
		{
			if(last)
			{
				int y=min(-x,d-get(1,1,n,b[last],n));
				modify(1,1,n,b[last],n,y);
				x+=y;
			}
			if(x<0)
			{
				last=i;
				ans++;
				modify(1,1,n,b[i],n,-x);
			}
		}
		if(get(1,1,n,1,n)>d)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}