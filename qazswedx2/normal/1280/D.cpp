#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int tt,n,m,f[3005][3005],h[100005],t,a[100005],size[100005],tf[3005];
ll g[3005][3005],tg[3005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u][1]=0,g[u][1]=a[u];
	size[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		for(int j=size[u];j;j--)
		{
			tf[j]=f[u][j];
			tg[j]=g[u][j];
		}
		for(int j=size[u]+size[v];j;j--)
			f[u][j]=0,g[u][j]=-1e18;
		for(int j=size[u];j;j--)
			for(int k=size[v];k;k--)
			{
				int nw1=tf[j]+f[v][k]+(g[v][k]>0),nw2=tf[j]+f[v][k];
				if(f[u][j+k]<nw1||f[u][j+k]==nw1&&g[u][j+k]<tg[j])
				{
					f[u][j+k]=nw1;
					g[u][j+k]=tg[j];
				}
				if(f[u][j+k-1]<nw2||f[u][j+k-1]==nw2&&g[u][j+k-1]<tg[j]+g[v][k])
				{
					f[u][j+k-1]=nw2;
					g[u][j+k-1]=tg[j]+g[v][k];
				}
			}
		size[u]+=size[v];
	}
	//printf("u=%d\n",u);
	//for(int i=1;i<=size[u];i++)
	//	printf("f=%d,g=%d\n",f[u][i],g[u][i]);
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			h[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i]=-a[i];
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[i]+=x;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		printf("%d\n",f[1][m]+(g[1][m]>0));
	}
	return 0;
}