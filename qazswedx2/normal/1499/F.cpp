#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[100005],t,f[5005][5005];
int tmp[5005],d[5005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u][0]=1;
	d[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		memcpy(tmp,f[u],sizeof(tmp));
		memset(f[u],0,sizeof(f[u]));
		for(int j=0;j<=d[u];j++)
			for(int k=0;k<=d[v];k++)
			{
				f[u][j]=addmod(f[u][j]+1ll*tmp[j]*f[v][k]%mod);
				if(j+k+1<=m)
				{
					f[u][max(j,k+1)]=addmod(f[u][max(j,k+1)]+1ll*tmp[j]*f[v][k]%mod);
				}
			}
		d[u]=max(d[u],d[v]+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=m;i++)
		ans=addmod(ans+f[1][i]);
	printf("%d\n",ans);
	return 0;
}