#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,q[500005][3];
struct Tree
{
	struct edge
	{
		int v,nxt;
	}e[1000005];
	int f[1000005],h[1000005],dfn[1000005],t,pt,cnt,lmn[1000005],lmx[1000005];
	int sz[1000005];
	void add(int u,int v)
	{
		e[++t].v=v;
		e[t].nxt=h[u];
		h[u]=t;
	}
	int find(int x)
	{
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	void link(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		f[x]=y;
		sz[y]+=sz[x];
	}
	void dfs(int u,int fa)
	{
		if(u&&u<=n)
		{
			dfn[u]=++cnt;
			lmn[u]=lmx[u]=dfn[u];
		}
		else lmn[u]=1e9,lmx[u]=0;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v==fa) continue;
			dfs(v,u);
			lmn[u]=min(lmn[u],lmn[v]);
			lmx[u]=max(lmx[u],lmx[v]);
		}
	//	printf("dfs:u=%d,fa=%d,dfn=%d,l=%d,%d\n",u,fa,dfn[u],lmn[u],lmx[u]);
	}
}T[2];
int rt[500005],ls[7000005],lrs[7000005],rs[7000005];
int mx[2000005],lazy[2000005],ct;
ll sum[7000005];
void pushup2(int x)
{
	mx[x]=max(mx[x*2],mx[x*2+1]);
}
void col(int x,int v)
{
	mx[x]=max(mx[x],v);
	lazy[x]=max(lazy[x],v);
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
}
void modify2(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify2(x*2,l,mid,ql,qr,v);
	modify2(x*2+1,mid+1,r,ql,qr,v);
	pushup2(x);
}
int query2(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return 0;
	if(l==r) return mx[x];
	pushdown(x);
	int mid=(l+r)/2;
	return max(query2(x*2,l,mid,qx),query2(x*2+1,mid+1,r,qx));
}
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]]+sum[lrs[x]];
}
int modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return x;
	int y=++ct;
	sum[y]=sum[x],ls[y]=ls[x],rs[y]=rs[x],lrs[y]=lrs[x];
	if(l==r)
	{
		sum[y]+=v;
		return y;
	}
	int mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
	ls[y]=modify(ls[x],l,mid1,qx,v);
	lrs[y]=modify(lrs[x],mid1+1,mid2,qx,v);
	rs[y]=modify(rs[x],mid2+1,r,qx,v);
	pushup(y);
	return y;
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql||!x) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
	return query(ls[x],l,mid1,ql,qr)+query(lrs[x],mid1+1,mid2,ql,qr)+query(rs[x],mid2+1,r,ql,qr);
}
int main()
{
	scanf("%d%d",&n,&m);
	T[0].pt=T[1].pt=n;
	for(int i=1;i<=m;i++)
	{
		char ch;
		int x,y=0;
		scanf(" %c%d",&ch,&x);
		if(ch=='U'||ch=='M') scanf("%d",&y);
		q[i][0]=ch,q[i][1]=x,q[i][2]=y;
	}
	for(int i=1;i<=2*n;i++)
		T[0].f[i]=T[1].f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(q[i][0]=='U'||q[i][0]=='M')
		{
			int u=q[i][1],v=q[i][2],fl=q[i][0]=='M';
			u=T[fl].find(u),v=T[fl].find(v);
			T[fl].pt++;
			T[fl].link(u,T[fl].pt);
			T[fl].link(v,T[fl].pt);
			T[fl].add(T[fl].pt,u);
			T[fl].add(T[fl].pt,v);
		}
	}
	for(int fl=0;fl<2;fl++)
		for(int i=1;i<=T[fl].pt;i++)
			if(T[fl].f[i]==i)
				T[fl].add(0,i);
	T[0].dfs(0,0);
	T[1].dfs(0,0);
	for(int i=1;i<=2*n;i++)
		T[0].f[i]=T[1].f[i]=i,T[0].sz[i]=T[1].sz[i]=(i<=n);
	T[0].pt=T[1].pt=n;
	for(int i=1;i<=m;i++)
	{
		rt[i]=rt[i-1];
		if(q[i][0]=='U'||q[i][0]=='M')
		{
			int u=q[i][1],v=q[i][2],fl=q[i][0]=='M';
			u=T[fl].find(u),v=T[fl].find(v);
			T[fl].pt++;
			T[fl].link(u,T[fl].pt);
			T[fl].link(v,T[fl].pt);
		}
		if(q[i][0]=='A')
		{
			int u=T[0].find(q[i][1]);
		//	printf("A:u=%d,l=%d,%d,sz=%d\n",u,T[0].lmn[u],T[0].lmx[u],T[0].sz[u]);
			rt[i]=modify(rt[i],1,n,T[0].lmn[u],T[0].sz[u]);
			rt[i]=modify(rt[i],1,n,T[0].lmx[u]+1,-T[0].sz[u]);
		}
		if(q[i][0]=='Z')
		{
			int u=T[1].find(q[i][1]);
			modify2(1,1,n,T[1].lmn[u],T[1].lmx[u],i);
		//	printf("Z:u=%d,l=%d,%d\n",u,T[1].lmn[u],T[1].lmx[u]);
		}
		if(q[i][0]=='Q')
		{
			int u=q[i][1];
			int las=query2(1,1,n,T[1].dfn[u]);
		//	printf("Q:las=%d,dfn=%d\n",las,T[1].dfn[u]);
			ll ans=query(rt[i],1,n,1,T[0].dfn[u])-query(rt[las],1,n,1,T[0].dfn[u]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}