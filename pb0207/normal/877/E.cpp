#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

struct E{
	int ne,to;
}edg[N*2+1];

struct T{
	int l,r,ls,rs;
	int sum,tag;
}t[N*2+1];

int n,a[N],st[N],ed[N],cnt,tot,totw,head[N];

void adde(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int f)
{
	st[i]=ed[i]=++totw;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dfs(v,i);
	}
	ed[i]=totw;
}

void update(int x)
{
	t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		if(t[x].ls)
		{
			int ls=t[x].ls;
			t[ls].sum=t[ls].r-t[ls].l+1-t[ls].sum;
			t[ls].tag^=1;
		}
		if(t[x].rs)
		{
			int rs=t[x].rs;
			t[rs].sum=t[rs].r-t[rs].l+1-t[rs].sum;
			t[rs].tag^=1;
		} 
		t[x].tag^=1;
	}
}

int build(int l,int r)
{
	int x=++tot;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].sum=a[l];
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int l,int r,int v)
{
	pushdown(x);
	if(t[x].l>=l&&t[x].r<=r)
	{
		t[x].tag^=1;
		t[x].sum=t[x].r-t[x].l+1-t[x].sum;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		change(t[x].ls,l,r,v);
	if(r>mid)
		change(t[x].rs,l,r,v);
	update(x);
}

int query(int x,int l,int r)
{
	pushdown(x);
	if(t[x].l>=l&&t[x].r<=r)
		return t[x].sum;
	int ret=0;
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		ret+=query(t[x].ls,l,r);
	if(r>mid)
		ret+=query(t[x].rs,l,r);
	update(x);
	return ret;
}

int b[N];

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		adde(p,i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		a[st[i]]=b[i];
	build(1,n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char op[10];
		int x;
		scanf("%s",op);
		scanf("%d",&x);
		if(op[0]=='p')
			change(1,st[x],ed[x],1);
		else
			printf("%d\n",query(1,st[x],ed[x]));
	}
}