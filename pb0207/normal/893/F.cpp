#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=3e5+1e3+7;

int n,r,head[N],cnt,st[N],ed[N],totw,a[N],dep[N],m,last,rev[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

struct E{
	int ne,to;
}edg[N*2+1];

void add(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int f)
{
	st[i]=ed[i]=++totw;
	rev[st[i]]=i;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dep[v]=dep[i]+1;
		dfs(v,i);
	}
	ed[i]=totw;
}

int sgcnt;

struct T{
	int l,r,ls,rs;
}t[N*2+1];

int stcnt,root[N*2+1];

struct TT{
	int ls,rs,mn;
}w[N*51+1];

void insert(int &x,int l,int r,int p,int v)
{
	if(!x)
		x=++stcnt,w[x].mn=0x7fffffff;
	if(l==r)
	{
		w[x].mn=min(w[x].mn,v);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		insert(w[x].ls,l,mid,p,v),w[x].mn=min(w[x].mn,w[w[x].ls].mn);
	else
		insert(w[x].rs,mid+1,r,p,v),w[x].mn=min(w[x].mn,w[w[x].rs].mn);
}

int build(int l,int r)
{
	int x=++sgcnt;
	t[x].l=l,t[x].r=r;
	for(int i=l;i<=r;i++)
		insert(root[x],1,n,dep[rev[i]],a[rev[i]]);
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

int qr(int x,int L,int R,int l,int r)
{
	if(L>=l&&R<=r)
		return w[x].mn;
	int mid=(L+R)>>1;
	int ret=0x7fffffff;
	if(l<=mid&&w[x].ls)
		ret=min(ret,qr(w[x].ls,L,mid,l,r));
	if(r>mid&&w[x].rs)
		ret=min(ret,qr(w[x].rs,mid+1,R,l,r));
	return ret;
}

int query(int x,int l,int r,int v)
{
	if(t[x].l>=l&&t[x].r<=r)
		return qr(root[x],1,n,1,v);
	int mid=(t[x].l+t[x].r)>>1;
	int ret=0x7fffffff;
	if(l<=mid)
		ret=min(ret,query(t[x].ls,l,r,v));
	if(r>mid)
		ret=min(ret,query(t[x].rs,l,r,v));
	return ret;
}

int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dep[r]=1;
	dfs(r,0);
	build(1,n);
	scanf("%d",&m);
	while(m--)
	{
		int x,p;
		x=read(),p=read();
		x=(x+last)%n+1,p=(p+last)%n;
		printf("%d\n",last=query(1,st[x],ed[x],dep[x]+p));
	}
}
/*
5 2
1 3 2 3 5
2 3
5 1
3 4
4 1
2
1 2
2 3
*/