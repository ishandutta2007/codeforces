#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf ((int)1e9+7)
struct edge
{
	int v,nxt;
}e[500005],e2[500005];
int n,m,h[500005],h2[500005],t,t2,cnt,pt,low[500005],dfn[500005],st[500005],tp;
int val[500005],udfn[500005],size[500005],d[500005],son[500005],f[500005];
int top[500005],sum[2000005],q,vis[500005];
multiset<int> mp[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	//printf("%d %d\n",u,v);
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
void tarjan(int u)
{
	low[u]=dfn[u]=++cnt;
	st[++tp]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]==dfn[u])
			{
				pt++;
				while(st[tp+1]!=v)
				{
					add2(st[tp],pt);
					add2(pt,st[tp]);
					vis[st[tp]]=1;
					tp--;
				}
				add2(pt,u),add2(u,pt);
			}
		}
		else if(!vis[v])
			low[u]=min(low[u],dfn[v]);
	}
}
void dfs1(int u,int fa,int dep)
{
	f[u]=fa;
	d[u]=dep;
	size[u]=1;
	son[u]=0;
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs1(v,u,dep+1);
		size[u]+=size[v];
		if(size[son[u]]<size[v])
			son[u]=v;
	}
}
void dfs2(int u,int ttp)
{
	top[u]=ttp;
	dfn[u]=++cnt;
	udfn[cnt]=u;
	//printf("u=%d,cnt=%d\n",u,cnt);
	if(son[u]) dfs2(son[u],ttp);
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=val[udfn[l]];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int qv)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=qv;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,qv);
	modify(x*2+1,mid+1,r,qx,qv);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	//printf("x=%d,l=%d,r=%d,ql=%d,qr=%d,sum=%d\n",x,l,r,ql,qr,sum[x]);
	if(l>qr||r<ql) return inf;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr);
	q2=query(x*2+1,mid+1,r,ql,qr);
	return min(q1,q2);
}
int tquery(int u,int v)
{
	int ans=inf;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]]) swap(u,v);
		ans=min(ans,query(1,1,pt,dfn[top[u]],dfn[u]));
		u=f[top[u]];
	}
	if(d[u]>d[v]) swap(u,v);
	if(u>n) ans=min(ans,val[f[u]]);
	if(dfn[u]>dfn[v]) swap(u,v);
	return min(ans,query(1,1,pt,dfn[u],dfn[v]));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	pt=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	tarjan(1);
	cnt=0;
	memset(dfn,0,sizeof(dfn));
	dfs1(1,0,0);
	dfs2(1,1);
	for(int i=2;i<=n;i++)
		mp[f[i]].insert(val[i]);
	for(int i=n+1;i<=pt;i++)
		val[i]=*(mp[i].begin());
	build(1,1,pt);
	for(int i=1;i<=q;i++)
	{
		char ch;
		int x,y;
		scanf(" %c%d%d",&ch,&x,&y);
		if(ch=='C')
		{
			mp[f[x]].erase(val[x]);
			mp[f[x]].insert(y);
			val[f[x]]=*(mp[f[x]].begin());
			val[x]=y;
			modify(1,1,pt,dfn[f[x]],val[f[x]]);
			modify(1,1,pt,dfn[x],val[x]);
			//printf("f[x]=%d,val=%d,%d\n",f[x],val[x],val[f[x]]);
		}
		else
		{
			printf("%d\n",tquery(x,y));
		}
	}
//	printf("cnt=%d\n",cnt);
	return 0;
}