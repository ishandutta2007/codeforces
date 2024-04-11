#include<bits/stdc++.h>
using namespace std;

const int M=2*1e5+10;
int id[M],size[M],n,m;

struct node
{
	int to,next;
}e[M*2];
int sa,head[M];
void adde(int u,int to)
{
	e[++sa].to=to,e[sa].next=head[u],head[u]=sa;
}

int cnt=0;
void dfs(int u,int fa)
{
	id[u]=++cnt,size[u]=1;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs(e[i].to,u),size[u]+=size[e[i].to];
}

struct tree
{
	struct node
	{
		int l,r;
		int tag,val;
	}tree[M<<2];
	#define l(x) tree[(x)].l
	#define r(x) tree[(x)].r
	#define mid(x) (tree[(x)].l+tree[(x)].r>>1)
	#define tag(x) tree[(x)].tag
	#define val(x) tree[(x)].val
	#define lson x<<1
	#define rson x<<1|1
	int a[M];
	void pushdown(int x)
	{
		if(tag(x))
		{
			tag(lson)^=1,val(lson)=r(lson)-l(lson)+1-val(lson);
			tag(rson)^=1,val(rson)=r(rson)-l(rson)+1-val(rson);
			tag(x)=0;
		}
	} 
	void pushup(int x)
	{
		val(x)=val(lson)+val(rson);
	}
	void build(int x,int l,int r)
	{
		l(x)=l,r(x)=r;tag(x)=0;
		if(l==r){val(x)=a[l];return;}
		build(lson,l(x),mid(x));
		build(rson,mid(x)+1,r(x));
		pushup(x);
	}
	void change(int x,int l,int r)
	{ 
		if(r<l(x)||r(x)<l)return;
		if(l<=l(x)&&r(x)<=r){
			tag(x)^=1;
			val(x)=r(x)-l(x)+1-val(x);
			return;
		}
		pushdown(x);
		change(lson,l,r);
		change(rson,l,r);
		pushup(x);
	}
	int query(int x,int l,int r)
	{
		if(r<l(x)||r(x)<l)return 0;
		if(l<=l(x)&&r(x)<=r)return val(x);
		pushdown(x);
		return query(lson,l,r)+query(rson,l,r); 
	}
}T;

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		adde(i,k),adde(k,i);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		T.a[id[i]]=a;
	}
	T.build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		string a;
		cin>>a;
		if (a=="pow")
		{
			int k;
			scanf("%d",&k);
			T.change(1,id[k],id[k]+size[k]-1);
		}
		else
		{
			int k;
			scanf("%d",&k);
			printf("%d\n",T.query(1,id[k],id[k]+size[k]-1));
		}
	}
	return 0;
}