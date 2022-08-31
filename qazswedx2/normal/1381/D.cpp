#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
struct pt
{
	int v1,v2,v3;
	pt(int v1=0,int v2=0,int v3=0):v1(v1),v2(v2),v3(v3){}
	void ins(int x)
	{
		if(x>v1)
		{
			v3=v2;
			v2=v1;
			v1=x;
		}
		else if(x>v2)
		{
			v3=v2;
			v2=x;
		}
		else if(x>v3)
			v3=x;
	}
	void add()
	{
		v1++,v2++,v3++;
	}
};
pt operator+(const pt x,const pt y)
{
	pt z=x;
	z.ins(y.v3);
	z.ins(y.v2);
	z.ins(y.v1);
	return z;
}
pt f[100005],g[100005];
int tt,n,s,t,h[100005],tot,d[100005],c[100005][22];
int mxd[100005],mxid[100005],vis[100005];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int dfs2(int u,int fa,int to)
{
	if(u==to) return 0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		int q=dfs2(v,u,to);
		if(q!=-1) return q+1;
	}
	return -1;
}
void dfs(int u,int fa)
{
	f[u]=pt(-1,-1e9,-1e9);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		f[u].ins(f[v].v1);
	}
	f[u].add();
}
pt tmp[100005],pre[100005],suf[100005];
int ct;
void dfs3(int u,int fa)
{
	ct=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		tmp[++ct]=pt(f[v].v1+1,-1e9,-1e9);
	}
	pre[0]=suf[ct+1]=pt(-1e9,-1e9,-1e9);
	for(int i=1;i<=ct;i++)
		pre[i]=pre[i-1]+tmp[i];
	for(int i=ct;i>=1;i--)
		suf[i]=suf[i+1]+tmp[i];
	ct=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		ct++;
		g[v]=pre[ct-1]+suf[ct+1];
		g[v].ins(g[u].v1);
		g[v].add();
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u);
	}
}
void dfs4(int u,int fa,int dep)
{
	d[u]=dep;
	c[u][0]=fa;
	for(int i=1;i<=18;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	mxd[u]=d[u],mxid[u]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs4(v,u,dep+1);
		if(mxd[u]<mxd[v])
		{
			mxd[u]=mxd[v];
			mxid[u]=mxid[v];
		}
	}
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
int getans(int u,int k)
{
	for(int i=18;i>=0;i--)
		if(k&(1<<i))
			u=c[u][i];
	return u;
}
int main()
{
//	freopen("CF1381D.in","r",stdin);
//	freopen("CF1381D.out","w",stdout);
	scanf("%d",&tt);
	while(tt--)
	{
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
		tot=0;
		scanf("%d%d%d",&n,&s,&t);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int l=dfs2(s,0,t),fl=0,id;
		dfs(1,0);
		dfs3(1,0);
		for(int i=1;i<=n;i++)
		{
			pt p=f[i];
			p.ins(g[i].v1);
		//	printf("i=%d,f=%d,%d,%d,g=%d,%d,%d,p=%d,%d,%d\n",i,f[i].v1,f[i].v2,f[i].v3,g[i].v1,g[i].v2,g[i].v3,p.v1,p.v2,p.v3);
			if(p.v3>=l)
			{
				fl=1;
				id=i;
				break;
			}
		}
		if(!fl)
		{
			printf("NO\n");
			continue;
		}
		dfs4(id,0,1);
		int dl=d[lca(s,t)];
		while(1)
		{
			int u=mxid[s];
			if(vis[u]) 
			{
				printf("NO\n");
				break;
			}
			vis[u]=1;
			t=getans(t,mxd[s]-d[s]);
			if(d[t]<=dl)
			{
				printf("YES\n");
				break;
			}
			s=u;
			swap(s,t);
		}
	}
	return 0;
}