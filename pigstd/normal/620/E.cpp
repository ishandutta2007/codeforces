#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=4*1e5+10;
int n,m;
int in[M],out[M],pos[M];

struct egde{int to,next;}e[M*2];
int head[M],sa;
void adde(int u,int to)
{e[++sa].to=to,e[sa].next=head[u],head[u]=sa;}

int cnt;
void dfs(int u,int fa)
{
	in[u]=++cnt;pos[cnt]=u;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs(e[i].to,u);
	out[u]=cnt;
}

int lowbit(int x)
{
	return x&(-x);
}

struct tree
{
	struct node
	{
		int tl,tr,sum,tag;
	}t[M<<2];
	int a[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define sum(x) t[(x)].sum
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		sum(k)=sum(lson)|sum(rson);
	}
	void pushdown(int k)
	{
		if (tag(k))
		{
			sum(lson)=tag(k),tag(lson)=tag(k);
			sum(rson)=tag(k),tag(rson)=tag(k);
			tag(k)=0;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){sum(k)=1ll<<a[pos[l]];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void change(int k,int l,int r,int p)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)
		{
			sum(k)=1ll<<p;
			tag(k)=1ll<<p;
			return;
		}
		pushdown(k);
		change(lson,l,r,p);change(rson,l,r,p);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return 0;
		if (l(k)>=l&&r(k)<=r)
			return sum(k);
		pushdown(k);
		int ret=query(lson,l,r)|query(rson,l,r);
		return ret;
	}
}T;

signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		scanf("%lld",&T.a[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		adde(x,y),adde(y,x);
	}
	dfs(1,0);
	T.build(1,1,n);
	while(m--)
	{
		int op;
		scanf("%lld",&op);
		if (op==1)
		{
			int v,c;
			scanf("%lld%lld",&v,&c);
			T.change(1,in[v],out[v],c);
		}
		else
		{
			int a;
			scanf("%lld",&a);
			int ans=T.query(1,in[a],out[a]);
			int sum=0;
			while(ans)sum++,ans-=lowbit(ans);
			printf("%lld\n",sum);
		}
	}
	return 0;
}