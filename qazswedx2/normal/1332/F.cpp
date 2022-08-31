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
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct edge
{
	int v,nxt;
}e[1000005];
int n,f[500005][3],h[500005],t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u][0]=f[u][1]=f[u][2]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		f[u][0]=1ll*f[u][0]*((2ll*f[v][0]+2ll*f[v][1]+f[v][2])%mod)%mod;
		f[u][1]=1ll*f[u][1]*((2ll*f[v][0]+f[v][1])%mod)%mod;
		f[u][2]=1ll*f[u][2]*((f[v][0]+f[v][1])%mod)%mod;
	}
	f[u][1]=submod(f[u][1]-f[u][2]);
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
	dfs(1,0);
	printf("%d",(addmod(f[1][0]+f[1][1])+mod-1)%mod);
	return 0;
}