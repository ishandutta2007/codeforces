#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
int tree[2000010],a[500010],opt,n,q;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
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
	tree[p]=gcd(tree[p<<1],tree[p<<1|1]);
}
void modify(int p,int le,int ri,int x,int y)
{
	if(le==ri)
	{
		tree[p]=y;
		return;
	}
	int mid=(le+ri)>>1;
	if(x<=mid)
	{
		modify(p<<1,le,mid,x,y);
	}
	else
	{
		modify(p<<1|1,mid+1,ri,x,y);
	}
	tree[p]=gcd(tree[p<<1],tree[p<<1|1]);
}
int getl(int p,int le,int ri,int l,int x)
{
	int mid=(le+ri)>>1;
	if(le>=l)
	{
		if(le==ri)
		{
			return tree[p]%x==0?le:le-1;
		}
		if(tree[p<<1]%x==0)
		{
			return getl(p<<1|1,mid+1,ri,l,x);
		}
		else
		{
			return getl(p<<1,le,mid,l,x);
		}
	}
	if(l>mid)
	{
		return getl(p<<1|1,mid+1,ri,l,x);
	}
	else
	{
		int tmp=getl(p<<1,le,mid,l,x);
		if(tmp==mid)
		{
			return getl(p<<1|1,mid+1,ri,l,x);
		}
		else
		{
			return tmp;
		}
	}
}
int getr(int p,int le,int ri,int r,int x)
{
	int mid=(le+ri)>>1;
	if(ri<=r)
	{
		if(le==ri)
		{
			return tree[p]%x==0?ri:ri+1;
		}
		if(tree[p<<1|1]%x==0)
		{
			return getr(p<<1,le,mid,r,x);
		}
		else
		{
			return getr(p<<1|1,mid+1,ri,r,x);
		}
	}
	if(r<=mid)
	{
		return getr(p<<1,le,mid,r,x);
	}
	else
	{
		int tmp=getr(p<<1|1,mid+1,ri,r,x);
		if(tmp==mid+1)
		{
			return getr(p<<1,le,mid,r,x);
		}
		else
		{
			return tmp;
		}
	}
}
bool query(int l,int r,int x)
{
	int ll=getl(1,1,n,l,x),rr=getr(1,1,n,r,x);
	return rr-ll<=2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			puts(query(l,r,x)?"YES":"NO");
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			modify(1,1,n,x,y);
		}
	}
	return 0;
}