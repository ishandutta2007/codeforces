#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[200005],t,f[200005],d[200005],e2[200005][2],et,c[200005],vis[200005];
int id,id2,a[200005],at,b[200005],bt,visp[200005],tans[4][200005],len[4];
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
int link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return 0;
	f[x]=y;
	return 1;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	c[u]=fa;
//	printf("dfs:u=%d,fa=%d,dep=%d\n",u,fa,dep);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
void modify(int u,int v,int w)
{
	if(d[u]<d[v]) swap(u,v);
	while(d[c[u]]>=d[v])
	{
		if(vis[u])
		{
			id=vis[u];
			id2=w;
			return;
		}
		vis[u]=w;
		u=c[u];
	}
	while(u!=v)
	{
		if(vis[u])
		{
			id=vis[u];
			id2=w;
			return;
		}
		if(vis[v])
		{
			id=vis[v];
			id2=w;
			return;
		}
		vis[u]=vis[v]=w;
		u=c[u],v=c[v];
	}
}
bool dfs2(int u,int fa,int to)
{
	if(u==to)
	{
		a[++at]=u;
		return 1;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(dfs2(v,u,to))
		{
			a[++at]=u;
			return 1;
		}
	}
	return 0;
}
int U=-1,V=-1;
void upd(int x)
{
	if(U==-1)
		U=x;
	else if(V==-1&&x!=U)
		V=x;
}
bool check(int x,int y)
{
	if(len[x]!=len[y]) return 0;
	for(int i=1;i<=len[x];i++)
		if(tans[x][i]!=tans[y][i])
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(link(u,v))
		{
			add(u,v);
			add(v,u);
		}
		else
		{
			e2[++et][0]=u;
			e2[et][1]=v;
		}
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
		{
			dfs(i,0,1);
		}
	for(int i=1;i<=et;i++)
	{
		modify(e2[i][0],e2[i][1],i);
		if(id) break;
	}
	if(!id)
	{
		printf("NO\n");
		return 0;
	}
	dfs2(e2[id][0],0,e2[id][1]);
	bt=at;
	for(int i=1;i<=bt;i++)
		b[i]=a[i];
	at=0;
	dfs2(e2[id2][0],0,e2[id2][1]);
	printf("YES\n");
	for(int i=1;i<=at;i++)
		visp[a[i]]++;
	for(int i=1;i<=bt;i++)
		visp[b[i]]++;
	for(int i=1;i<=at;i++)
		if(visp[a[i]]==2&&(visp[a[i==1?at:i-1]]!=2||visp[a[i%at+1]]!=2))
			upd(a[i]);
	for(int i=1;i<=bt;i++)
		if(visp[b[i]]==2&&(visp[b[i==1?bt:i-1]]!=2||visp[b[i%bt+1]]!=2))
			upd(b[i]);
/*	printf("U=%d,V=%d\n",U,V);
	for(int i=1;i<=at;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=bt;i++)
		printf("%d ",b[i]);
	printf("\n");*/
	int q1=-1,q2=-1;
	for(int i=1;i<=at;i++)
	{
		if(a[i]==U) q1=i;
		if(a[i]==V) q2=i;
	}
	for(int i=q1;i!=q2;i=i%at+1)
		tans[0][++len[0]]=a[i];
	tans[0][++len[0]]=a[q2];
	for(int i=q2;i!=q1;i=i%at+1)
		tans[1][++len[1]]=a[i];
	tans[1][++len[1]]=a[q1];
	reverse(tans[1]+1,tans[1]+len[1]+1);
	for(int i=1;i<=bt;i++)
	{
		if(b[i]==U) q1=i;
		if(b[i]==V) q2=i;
	}
	for(int i=q1;i!=q2;i=i%bt+1)
		tans[2][++len[2]]=b[i];
	tans[2][++len[2]]=b[q2];
	for(int i=q2;i!=q1;i=i%bt+1)
		tans[3][++len[3]]=b[i];
	tans[3][++len[3]]=b[q1];
	reverse(tans[3]+1,tans[3]+len[3]+1);
	for(int i=0;i<4;i++)
	{
		int fl=1;
		for(int j=0;j<i;j++)
			if(check(i,j))
			{
				fl=0;
				break;
			}
		if(fl)
		{
			printf("%d ",len[i]);
			for(int j=1;j<=len[i];j++)
				printf("%d ",tans[i][j]);
			printf("\n");
		}
	}
	return 0;
}