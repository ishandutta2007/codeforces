#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,pt,a[100005],h[100005],t,rt,qrt,ls[100005],rs[100005],f[100005],q;
int sz[100005],vis[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u)
{
	if(!ls[u]&&!rs[u])
	{
		a[u]=u;
		return;
	}
	dfs(ls[u]);
	dfs(rs[u]);
	a[u]=a[ls[u]];
}
void dfs1(int u,int fa)
{
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa,int ssz)
{
	int mx=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,ssz);
		mx=max(mx,sz[v]);
	}
	mx=max(mx,ssz-sz[u]);
	if(mx<=ssz/2) qrt=u;
}
void dfz(int u)
{
	vis[u]=0;
	dfs1(u,0);
	if(sz[u]==2)
	{
		pt++;
		int v;
		if(!vis[f[u]]) u=f[u];
		if(!vis[ls[u]])
		{
			v=ls[u];
			ls[u]=pt,f[pt]=u;
			ls[pt]=v,f[v]=pt;
			rs[pt]=q,f[q]=pt;
		}
		else if(!vis[rs[u]])
		{
			v=rs[u];
			rs[u]=pt,f[pt]=u;
			rs[pt]=v,f[v]=pt;
			ls[pt]=q,f[q]=pt;
		}
		return;
	}
	dfs2(u,0,sz[u]);
//	printf("qrt=%d\n",qrt);
//	for(int i=1;i<=pt;i++)
//		if(f[i]||ls[i]||rs[i])
//			printf("i=%d,f=%d,ls=%d,rs=%d,vis=%d,a=%d\n",i,f[i],ls[i],rs[i],vis[i],a[i]);
	printf("%d %d %d\n",a[ls[qrt]],a[rs[qrt]],q);
	fflush(stdout);
	char ch;
	scanf(" %c",&ch);
	int x=f[qrt],y=ls[qrt],z=rs[qrt];
	vis[x]=vis[y]=vis[z]=1;
	if(ch=='X')
	{
		if(!f[qrt])
		{
			pt++;
			ls[pt]=qrt,f[qrt]=pt;
			rs[pt]=q,f[q]=pt;
			rt=pt;
			return;
		}
		dfz(f[qrt]); 
	}
	else if(ch=='Z') dfz(ls[qrt]);
	else dfz(rs[qrt]);
}
void solve()
{
	for(int i=1;i<=pt;i++)
		h[i]=vis[i]=0;
	t=0;
	for(int i=1;i<=pt;i++)
		if(f[i]) add(i,f[i]),add(f[i],i);
	dfs(rt);
	dfz(rt);
}
int main()
{
	scanf("%d",&n);
	rt=pt=n+1;
	ls[pt]=1,f[1]=pt;
	rs[pt]=2,f[2]=pt;
	for(int i=3;i<=n;i++)
	{
		q=i;
		solve();
	}
	printf("-1\n");
	for(int i=1;i<=pt;i++)
		if(!f[i]) printf("-1 ");
		else printf("%d ",f[i]);
	return 0;
}