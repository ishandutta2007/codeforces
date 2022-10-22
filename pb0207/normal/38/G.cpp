#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,c[N],a[N];

int root,tot,son[N][2],fa[N],key[N],val[N],mx[N],size[N];

void update(int x)
{
	mx[x]=max(val[x],max(mx[son[x][1]],mx[son[x][0]]));
	size[x]=size[son[x][0]]+size[son[x][1]]+1;
}

void rotate(int x)
{
	int y=fa[x],z=fa[y],t=(son[y][0]==x);
	if(z)
		son[z][son[z][1]==y]=x;
	fa[x]=z;
	son[y][!t]=son[x][t];
	fa[son[x][t]]=y;
	son[x][t]=y;
	fa[y]=x;
	update(y);
	update(x);
}

void splay(int x,int s)
{
	while(fa[x]!=s)
	{
		int y=fa[x],z=fa[y];
		if(z!=s)
		{
			if((son[y][0]==x)^(son[z][0]==y))
				rotate(x);
			else
				rotate(y);
		}
		rotate(x);
	}
	if(!s)
		root=x;
}

void insert(int &x,int s,int va,int o)
{
 	x=++tot;
 	key[x]=o;
 	fa[x]=s;
 	val[x]=va;
 	mx[x]=va;
 	size[x]=1;
 	return;
}

int kth(int k)
{
	int x=root;
	while(k<=size[son[x][0]]||k>size[son[x][0]]+1)
	{
		if(k<=size[son[x][0]])
			x=son[x][0];
		else
			k-=size[son[x][0]]+1,x=son[x][1];
	}
	return x;
}

bool chk(int o,int v)
{
	int p=kth(o+1);
	splay(p,0);
	return max(val[p],mx[son[p][1]])>=v;
}

void out(int x)
{
	if(!x)
		return;
	out(son[x][0]);
	if(key[x])
		printf("%d ",key[x]);
	out(son[x][1]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&c[i]),c[i]=min(c[i],i-1);
	insert(root,0,0,0);
	insert(son[root][1],root,0,0);
	for(int i=1;i<=n;i++)
	{
		int l=i-c[i]-1,r=i;
		while(r-l>1)
		{  
			int mid=(l+r)>>1;
			if(chk(mid,a[i]))
				l=mid;
			else
				r=mid;
		}
		int x=kth(l+1),y=kth(r+1);
		splay(x,0);
		splay(y,x);
		int idx=0;
		insert(idx,0,a[i],i);
		son[y][0]=idx;
		fa[idx]=y; 
		update(y);
		update(x);
//		out(root);
//		puts("");
	}
	out(root);
}