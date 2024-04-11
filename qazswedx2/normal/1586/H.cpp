#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,c,nxt;
}e[500005];
struct pt
{
	int x,v,id;
	bool operator<(const pt p) const
	{
		return v<p.v;
	}
}b[200005];
int n,m,e2[500005][4],h[200005],t,c[200005][22],d[200005],p[200005][22],a[200005];
int f[200005],g[200005],tans[200005],q[200005],qans[200005][2];
void add(int u,int v,int w,int c)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].c=c;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep,int ww)
{
	d[u]=dep;
	c[u][0]=fa;
	p[u][0]=ww;
	for(int i=1;i<=18;i++)
	{
		c[u][i]=c[c[u][i-1]][i-1];
		p[u][i]=max(p[u][i-1],p[c[u][i-1]][i-1]);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dfs(v,u,dep+1,w);
	}
}
int getans(int u,int v)
{
	int ans=0;
	if(d[u]<d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
		{
			ans=max(ans,p[u][i]);
			u=c[u][i];
		}
	if(u==v) return ans;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
		{
			ans=max(ans,max(p[u][i],p[v][i]));
			u=c[u][i];
			v=c[v][i];
		}
	ans=max(ans,max(p[u][0],p[v][0]));
	return ans;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	if(a[g[x]]==a[g[y]])
		tans[y]=max(max(tans[x],tans[y]),getans(g[x],g[y]));
	else if(a[g[x]]>a[g[y]])
	{
		g[y]=g[x];
		tans[y]=tans[x];
	}
}
bool cmp(const int x,const int y)
{
	return e2[x][3]<e2[y][3];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v,w,c;
		scanf("%d%d%d%d",&u,&v,&c,&w);
		c=-c;
		add(u,v,w,c);
		add(v,u,w,c);
		e2[i][0]=u,e2[i][1]=v,e2[i][2]=w,e2[i][3]=c;
		q[i]=i;
	}
	dfs(1,0,1,0);
	sort(q+1,q+n,cmp);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].v,&b[i].x);
		b[i].id=i; 
		b[i].v=-b[i].v;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
		f[i]=g[i]=i;
	int nw=1;
	for(int i=1;i<=m;i++)
	{
		int v=b[i].v,x=b[i].x;
		while(nw<n&&e2[q[nw]][3]<=v)
		{
			int u=e2[q[nw]][0],v=e2[q[nw]][1];
			link(u,v);
			nw++;
		}
		x=find(x);
		//printf("i=%d,nw=%d,b=%d,%d,x=%d,g=%d,a=%d,tans=%d\n",i,nw,b[i].v,b[i].x,x,g[x],a[g[x]],tans[x]);
		qans[b[i].id][0]=a[g[x]];
		qans[b[i].id][1]=max(getans(b[i].x,g[x]),tans[x]);
	}
	for(int i=1;i<=m;i++)
		printf("%d %d\n",qans[i][0],qans[i][1]);
	return 0;
}