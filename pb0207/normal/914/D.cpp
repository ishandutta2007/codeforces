#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e5+1e3+7;

struct node{
	int l,r,ls,rs,g;
}t[N*2+1];

int cnt=0;

int n,a[N];

void update(int x)
{
	t[x].g=__gcd(t[t[x].ls].g,t[t[x].rs].g);
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].g=a[l];
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int p,int v)
{
	if(t[x].l==t[x].r)
	{
		t[x].g=v;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		change(t[x].ls,p,v);
	else
		change(t[x].rs,p,v);
	update(x);
}

int query(int x,int l,int r,int v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		if(t[x].l==t[x].r)
		{
			return t[x].g%v!=0?0:1;
		}
		if(t[x].g%v!=0)
		{
			if(t[t[x].ls].g%v!=0&&t[t[x].rs].g%v!=0)
				return -1;
			if(t[t[x].ls].g%v!=0)
				return query(t[x].ls,l,r,v)==-1?-1:0;
			if(t[t[x].rs].g%v!=0)
				return query(t[x].rs,l,r,v)==-1?-1:0;
		}
		return 1;
	}
	int mid=(t[x].l+t[x].r)>>1;
	int ret=0,c0=0;
	if(l<=mid)
	{
		int tmp=query(t[x].ls,l,r,v);
		c0+=(tmp==0);
		if(tmp==-1)
			return -1;
	}
	if(r>mid)
	{
		int tmp=query(t[x].rs,l,r,v);
		c0+=(tmp==0);
		if(tmp==-1)
			return -1;
	}
	if(c0==2)
		return -1;
	return c0?0:1;
}

int q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	build(1,n);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			puts(query(1,l,r,x)!=-1?"YES":"NO");
		}
		else
		{
			int p,x;
			scanf("%d%d",&p,&x);
			change(1,p,x);
		}
	}
}