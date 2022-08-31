#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,f[100005],g[100005],h[100005],t,sn,tans[100005],mx[100005],sd[100005],c[100005];
int cnt,udfn[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	udfn[++cnt]=u;
	c[u]=fa;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	} 
}
/*void dfs(int u,int fa,int len)
{
	f[u]=g[u]=0;
	int mx=0,sd=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,len);
		f[u]+=f[v];
		if(g[v]>mx)
		{
			sd=mx;
			mx=g[v];
		}
		else if(g[v]>sd)
			sd=g[v];
	}
	if(mx+sd+1>=len) f[u]++,g[u]=0;
	else g[u]=mx+1;
}*/
int getans(int x)
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(mx,0,sizeof(mx));
	memset(sd,0,sizeof(sd));
	for(int i=n;i>0;i--)
	{
		int u=udfn[i],fa=c[u];
		if(mx[u]+sd[u]+1>=x) f[u]++,g[u]=0;
		else g[u]=mx[u]+1;
		f[fa]+=f[u];
		//printf("u=%d,f=%d,g=%d\n",u,f[u],g[u]);
		if(g[u]>mx[fa])
		{
			sd[fa]=mx[fa];
			mx[fa]=g[u];
		}
		else if(g[u]>sd[fa])
			sd[fa]=g[u];
	}
	return f[1];
}
int main()
{
	scanf("%d",&n);
	sn=min(n,(int)(sqrt(n)*2));
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=sn;i++)
		tans[i]=getans(i);
	for(int i=sn+1,j;i<=n;i=j+1)
	{
		int l=i,r=n,mid,nw=getans(i);
		while(l<=r)
		{
			mid=(l+r)/2;
			if(nw==getans(mid)) l=mid+1;
			else r=mid-1;
		}
		j=r;
		for(int k=i;k<=j;k++)
			tans[k]=nw;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",tans[i]);
	return 0;
}