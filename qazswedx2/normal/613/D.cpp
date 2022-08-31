#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005],e2[500005];
int n,m,h[100005],h2[100005],t,t2,c[100005][21],d[100005],a[100005];
int st[100005],tp,vis[100005],tans,fl,ct,dfn[100005],b[100005],bt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
void dfs(int u,int fa,int dep)
{
	c[u][0]=fa;
	dfn[u]=++ct;
	for(int i=1;i<=19;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=19;i>=0;i--)
		if(d[c[u][i]]>=d[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
void dfs2(int u,int fa)
{
	//printf("u=%d,fa=%d\n",u,fa);
	b[++bt]=u;
	int cnt=0;
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		//printf("v=%d\n",v);
		if(v==fa) continue;
		dfs2(v,u);
		if(!vis[v]) continue;
		if(vis[u])
		{
			if(d[v]==d[u]+1&&vis[v]==1) fl=1;
			else tans++;
		}
		else cnt++;
	}
	if(cnt>=2) tans++;
	if(cnt==1) vis[u]=2;
	h2[u]=0;
}
bool cmp(const int x,const int y)
{
	return dfn[x]<dfn[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	scanf("%d",&m);
	dfs(1,0,1);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d",&a[j]),vis[a[j]]=1;
		sort(a+1,a+k+1,cmp);
		tp=1;
		st[1]=1;
		for(int j=1;j<=k;j++)
		{
			if(a[j]==1) continue;
			int l=lca(a[j],st[tp]);
			//printf("j=%d,l=%d\n",j,l);
			while(tp>1&&d[l]<=d[st[tp-1]])
			{
				add2(st[tp],st[tp-1]);add2(st[tp-1],st[tp]);
				tp--;
			}
			if(st[tp]!=l)
			{
				add2(st[tp],l);add2(l,st[tp]);
				st[tp]=l;
			}
			st[++tp]=a[j];
		}
		while(tp>1) add2(st[tp],st[tp-1]),add2(st[tp-1],st[tp]),tp--;
		fl=0;
		tans=0;
		bt=0;
		dfs2(1,0);
		for(int i=1;i<=bt;i++) vis[b[i]]=0;
		if(fl) printf("-1\n");
		else printf("%d\n",tans);
		t2=0;
		/*for(int i=1;i<=n;i++)
			printf("%d",vis[i]);
		printf("\n");*/
	}
	return 0;
}