#include<bits/stdc++.h>
using namespace std;

const int M=2*1e5+10;
int id[M],fa[M],n,q,son[M];

struct egde
{
	int to,next;
}a[M*2];int cnt,head[M];
void adde(int u,int to)
{
	a[++cnt].to=to,a[cnt].next=head[u],head[u]=cnt;
}

struct tree
{
	struct node
	{
		int tl,tr,tag,maxn;
		bool tag2;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define tag(x) t[(x)].tag
	#define tag2(x) t[(x)].tag2
	#define maxn(x) t[(x)].maxn
	#define lson k<<1
	#define rson k<<1|1
	void clear()
	{
		tag2(1)=1,tag(1)=maxn(1)=0;
	}
	void pushdown(int k)
	{
		if (tag2(k))
		{
			maxn(lson)=tag(lson)=0,tag2(lson)=1;
			maxn(rson)=tag(rson)=0,tag2(rson)=1;
			tag2(k)=0;
		}
		if (tag(k))
		{
			maxn(lson)+=tag(k),tag(lson)+=tag(k);
			maxn(rson)+=tag(k),tag(rson)+=tag(k);
			tag(k)=0;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,tag(k)=0;
		if (l==r)
			{maxn(k)=0;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid);build(rson,Mid+1,r);
		maxn(k)=max(maxn(lson),maxn(rson));
	}
	void change(int k,int l,int r,int z)
	{
		if(r<l(k)||r(k)<l)return;
		if(l<=l(k)&&r(k)<=r)
		{
			tag(k)+=z;
			maxn(k)+=z;
			return;
		}
		pushdown(k);
		change(lson,l,r,z),change(rson,l,r,z);
		maxn(k)=max(maxn(lson),maxn(rson));
	}
	int query(int k,int l,int r)
	{
		if(r<l(k)||r(k)<l)return 0;
		if(l<=l(k)&&r(k)<=r)return maxn(k);
		pushdown(k);
		return max(maxn(lson),maxn(rson));
	}
}T;

int sum=0;
void dfs(int u,int f)
{
	fa[u]=f,id[u]=++sum,son[u]=1;
	for (int i=head[u];i;i=a[i].next)
		if (a[i].to!=f)
			dfs(a[i].to,u),son[u]+=son[a[i].to];
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adde(x,y),adde(y,x);
	}
	dfs(1,0);
	T.build(1,1,n);
	while(q--)
	{
		T.clear();
		int k;
		scanf("%d",&k);
		for (int i=1;i<=k;i++)
		{
			int a;
			scanf("%d",&a);
			if (a==1)
				T.change(1,1,n,1);
			else
				T.change(1,id[fa[a]],id[fa[a]]+son[fa[a]]-1,1);
		}
		if (T.query(1,1,n)==k)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}