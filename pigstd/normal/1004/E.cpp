#include<bits/stdc++.h>
#define int long long
#define MAXN 1145141919180
using namespace std; 

const int M=3e5+10;
int n,k;
int dis[M],f[M],frm[M];
int vis[M],d[M];//d  
int maxd,maxn[M],dep[M];

struct node
{
	int next,to,w;
}e[M*2];
int head[M],cnt;
void add(int u,int to,int w)
{
	e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;
}

void dfs2(int u,int p,int pa)
{
	maxn[p]=max(maxn[p],dep[u]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==pa||vis[v])continue;
		dep[v]=dep[u]+e[i].w;
		dfs2(v,p,u);
	}
}

void dfs(int u,int fa)
{
	f[u]=fa;
	for (int i=head[u];i;i=e[i].next)
	{
		int to=e[i].to;
		if (to!=fa)
			dis[to]=dis[u]+e[i].w,frm[to]=i,dfs(to,u);
	}
}

signed main()
{
	cin>>n>>k;
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}
	int s=1,t=1;dfs(1,0);
	for (int i=1;i<=n;i++)
		if (dis[i]>dis[t])t=i;
	dis[t]=0;dfs(t,0);
	for (int i=1;i<=n;i++)
		if (dis[i]>dis[s])s=i;
	int u=s,kkk=0;
	while(u!=t)d[++kkk]=u,vis[u]=1,u=f[u];
	d[++kkk]=u,vis[u]=1;
	for (int i=1;i<=kkk;i++)
		dfs2(d[i],i,0),maxd=max(maxd,maxn[i]);
	int r=1,ans=MAXN;
	for (int l=1,r=k;l<=kkk;l++,r++)
		ans=min(ans,max(maxd,max(dis[d[r]],dis[s]-dis[d[l]])));
	cout<<ans;
	return 0;
}