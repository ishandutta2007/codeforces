#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
int n,f[1000005],fr[1000005],mod=998244353,h[1000005],t=0;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	int sz=1,ans=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		ans=1ll*ans*f[v]%mod;
		sz++;
	}
	ans=1ll*ans*fr[sz]%mod;
	f[u]=ans;
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
	}
	fr[0]=1;
	for(int i=1;i<=n;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	int ans=1,sz=0;
	for(int i=h[1];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs(v,1);
		ans=1ll*ans*f[v]%mod;
		sz++;
	}
	ans=1ll*ans*fr[sz]%mod*n%mod;
	printf("%d",ans);
	return 0;
}