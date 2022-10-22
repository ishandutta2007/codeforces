#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,f[51][N],a[N],k,last[N],vis[N],cnt;

struct node{
	int l,r,ls,rs;
	int tag,mx;
}t[N*2+1];

void update(int x)
{
	t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		int ls=t[x].ls,rs=t[x].rs;
		if(ls)
		{
			t[ls].mx+=t[x].tag;
			t[ls].tag+=t[x].tag;
		}
		if(rs)
		{
			t[rs].mx+=t[x].tag;
			t[rs].tag+=t[x].tag;
		}
		t[x].tag=0;
	}
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

void rebuild(int x,int k)
{
	t[x].tag=0;
	if(t[x].l==t[x].r)
	{
		t[x].mx=f[k][t[x].l-1];
		return;
	}
	rebuild(t[x].ls,k);
	rebuild(t[x].rs,k);
	update(x);
}

void add(int x,int l,int r,int v)
{
	pushdown(x);
	if(t[x].l>=l&&t[x].r<=r)
	{
		t[x].mx+=v;
		t[x].tag=v;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		add(t[x].ls,l,r,v);
	if(r>mid)
		add(t[x].rs,l,r,v);
	update(x);
}

int query(int x,int l,int r)
{
	pushdown(x);
	if(t[x].l>=l&&t[x].r<=r)
		return t[x].mx;
	int mid=(t[x].l+t[x].r)>>1;
	int ret=0;
	if(l<=mid)
		ret=max(ret,query(t[x].ls,l,r));
	if(r>mid)
		ret=max(ret,query(t[x].rs,l,r));
	update(x);
	return ret;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		last[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	build(1,n);
	for(int i=1;i<=k;i++)
	{
		rebuild(1,i-1);
		for(int j=1;j<=n;j++)
		{
			add(1,last[j]+1,j,1);
			f[i][j]=query(1,1,j);
		}
	}
	printf("%d",f[k][n]);
}