#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int T,n,a[100005][2],h[100005],t;
ll f[100005][2];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int F(int x)
{
	return x>=0?x:-x;
}
void dfs(int u,int fa)
{
	f[u][0]=f[u][1]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		f[u][0]=f[u][0]+max(f[v][0]+F(a[u][0]-a[v][0]),f[v][1]+F(a[u][0]-a[v][1]));
		f[u][1]=f[u][1]+max(f[v][0]+F(a[u][1]-a[v][0]),f[v][1]+F(a[u][1]-a[v][1]));
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=0;
		memset(h,0,sizeof(h));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i][0],&a[i][1]);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}