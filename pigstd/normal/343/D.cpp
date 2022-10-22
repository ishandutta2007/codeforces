#include<bits/stdc++.h>
using namespace std;

const int M=5*1e5+10;
int n,q;
int de[M],fa[M],son[M],size[M];
int w[M],id[M],top[M];

struct egde{int to,next;}e[M*2];
int head[M],sa;
void adde(int u,int to)
{e[++sa].to=to,e[sa].next=head[u],head[u]=sa;}

inline void dfs1(int x,int f)
{
	de[x]=de[f]+1,fa[x]=f,size[x]=1;int maxson=-1;
	for (int k=head[x];k;k=e[k].next)
		if (e[k].to!=f)
		{
			dfs1(e[k].to,x),size[x]+=size[e[k].to];
			if (size[e[k].to]>maxson)
				maxson=size[e[k].to],son[x]=e[k].to;
		}
}

int cnt;
inline void dfs2(int x,int topf)
{
	id[x]=++cnt,top[x]=topf;
	if (!son[x])return;
	dfs2(son[x],topf);
	for (int k=head[x];k;k=e[k].next)
		if (e[k].to!=fa[x]&&e[k].to!=son[x])
			dfs2(e[k].to,e[k].to);
}

struct tree
{
	struct node
	{
		int tl,tr,tag,w;
	}t[M<<2];
	#define tag(x) t[(x)].tag
	#define w(x) t[(x)].w
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k)
	{
		if (tag(k)!=-1)
		{
			w(lson)=tag(lson)=tag(k);
			w(rson)=tag(rson)=tag(k);
			tag(k)=-1;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,tag(k)=-1;
		if (l==r)
			return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void change(int k,int l,int r,int z)
	{
		if(l<=l(k)&&r(k)<=r)
		{
			tag(k)=z;
			w(k)=z;
			return;
		}
		pushdown(k);
		int Mid=(l(k)+r(k))>>1;
		if (l<=Mid)change(lson,l,r,z);
		if (r>Mid) change(rson,l,r,z);
	}
	int query(int k,int x)
	{
		if (l(k)==r(k))return w(k);
		pushdown(k);
		int Mid=(l(k)+r(k))>>1;
		if (x<=Mid)
			return query(lson,x);
		else
			return query(rson,x);
	}
}T;

inline void q1(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if (de[top[x]]<de[top[y]])swap(x,y);
		T.change(1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if (de[x]>de[y])swap(x,y);
	T.change(1,id[x],id[y],k);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b),adde(b,a);
	}
	dfs1(1,0);
	dfs2(1,1);
	T.build(1,1,n);
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==1)
			T.change(1,id[b],id[b]+size[b]-1,1);
		if (a==2)
			q1(1,b,0);
		if (a==3)
			printf("%d\n",T.query(1,id[b]));
	}
	return 0;
}