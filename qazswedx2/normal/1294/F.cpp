#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,f[500005][3],g[500005][3][3],rt,h[500005],t,a[500005],tans,id1,id2,id3;
int up[500005],upg[500005],b[500005],bt,c[500005],d[500005],cg[500005],dg[500005];
int bg[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u][0]=0;
	f[u][1]=f[u][2]=-1e9;
	g[u][0][0]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		if(f[u][1]+1+f[v][0]>f[u][2])
		{
			f[u][2]=f[u][1]+1+f[v][0];
			g[u][2][0]=g[v][0][0];
			g[u][2][1]=g[u][1][0];
			g[u][2][2]=g[u][1][1];
		}
		if(f[u][0]+1+f[v][1]>f[u][2])
		{
			f[u][2]=f[u][0]+1+f[v][1];
			g[u][2][0]=g[u][0][0];
			g[u][2][1]=g[v][1][0];
			g[u][2][2]=g[v][1][1];
		}
		if(f[u][0]+1+f[v][0]>f[u][1])
		{
			f[u][1]=f[u][0]+1+f[v][0];
			g[u][1][0]=g[v][0][0];
			g[u][1][1]=g[u][0][0];
		}
		if(1+f[v][0]>f[u][0])
		{
			f[u][0]=1+f[v][0];
			g[u][0][0]=g[v][0][0];
		}
	}
	if(tans<f[u][2])
	{
		tans=f[u][2];
		id1=g[u][2][0],id2=g[u][2][1],id3=g[u][2][2];
	}
}
void dfs2(int u,int fa)
{
	bt=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		b[++bt]=f[v][0]+1;
		bg[bt]=g[v][0][0];
	}
	c[0]=d[bt+1]=-1e9;
	for(int i=1;i<=bt;i++)
	{
		c[i]=max(b[i],c[i-1]);
		if(c[i]==b[i]) cg[i]=bg[i];
		else cg[i]=cg[i-1];
	}
	for(int i=bt;i>0;i--)
	{
		d[i]=max(b[i],d[i+1]);
		if(d[i]==b[i]) dg[i]=bg[i];
		else dg[i]=dg[i+1];
	}
	int ct=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		ct++;
		up[v]=max(max(c[ct-1],d[ct+1]),up[u])+1;
		if(up[v]==c[ct-1]+1) upg[v]=cg[ct-1];
		if(up[v]==d[ct+1]+1) upg[v]=dg[ct+1];
		if(up[v]==up[u]+1) upg[v]=upg[u];
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
	}
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
		a[u]++,a[v]++;
	}
	for(int i=1;i<=n;i++)
		if(a[i]>1)
		{
			rt=i;
			break;
		}
	dfs(rt,0);
	dfs2(rt,0);
	for(int i=1;i<=n;i++)
	{
		//printf("i=%d.up=%d,upg=%d,f=%d,%d,%d\n",i,up[i],upg[i],f[i][0],f[i][1],f[i][2]);
		if(i==rt) continue;
		if(up[i]+f[i][1]>tans)
		{
			tans=up[i]+f[i][1];
			id1=upg[i],id2=g[i][1][0],id3=g[i][1][1];
		}
	}
	printf("%d\n%d %d %d\n",tans,id1,id2,id3);
	return 0;
}