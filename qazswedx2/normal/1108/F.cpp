#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int u,v,w,vis;
}e1[5000005];
struct edge1
{
	int v,w,nxt;
}e[5000005];
int n,m,ans=0,f[500005],c[500005][20],h[500005],d[500005],g[500005][20],t;
void add(int u,int v,int w)
{
	//printf("<%d,%d,%d>\n",u,v,w);
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
bool cmp(const edge x,const edge y)
{
	return x.w<y.w;
}
void dfs(int u,int fa,int dep,int nw)
{
	c[u][0]=fa;
	g[u][0]=nw;
	d[u]=dep;
	for(int i=1;i<=18;i++)
		c[u][i]=c[c[u][i-1]][i-1],g[u][i]=max(g[u][i-1],g[c[u][i-1]][i-1]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dfs(v,u,dep+1,w);
	}
}
int getmax(int u,int v)
{
	//printf("u=%d,v=%d,",u,v);
	if(d[u]<d[v]) swap(u,v);
	int ans=0;
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
		{
			ans=max(ans,g[u][i]);
			u=c[u][i];
		}
	if(u==v) 
	{
		//printf("ans=%d\n",ans);
		return ans;
	}
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
		{
			ans=max(max(g[u][i],g[v][i]),ans);
			u=c[u][i],v=c[v][i];
		}
	//printf("ans=%d\n",max(max(g[u][0],g[v][0]),ans));
	return max(max(g[u][0],g[v][0]),ans);
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y,int w,int fr)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	add(x,y,w),add(y,x,w);
	e1[fr].vis=1;
	//printf("fr=%d\n",fr);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		//printf("u=%d,v=%d,w=%d\n",e1[i].u,e1[i].v,e1[i].w);
		link(e1[i].u,e1[i].v,e1[i].w,i);
	}
	dfs(1,1,1,0);
	for(int i=1;i<=m;i++)
		if(!e1[i].vis&&getmax(e1[i].u,e1[i].v)==e1[i].w)
			ans++;
	printf("%d",ans);
	return 0;
}