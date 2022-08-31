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
	int v,w,nxt;
}e[500005];
int n,h[100005],t,f[305][305][2],a[1005],lim,d[1005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	for(int i=0;i<lim;i++)
		f[u][i][0]=f[u][i][1]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		f[u][0][0]=1ll*f[u][0][0]*(1ll*f[v][0][0]+f[v][1][0]+f[v][1][1]+(d[v]-d[u]<lim))%mod;
		for(int j=1;j<lim;j++)
		{
			int nw=(1ll*f[v][j][0]+f[v][j+1][0]+f[v][j+1][1]+(d[v]-d[u]+j<lim))%mod;
			int nw2=addmod(nw+f[v][j-1][0]);
			f[u][j][0]=1ll*f[u][j][0]*nw2%mod;
			f[u][j][1]=1ll*f[u][j][1]*nw%mod;
		}
	}
	for(int i=1;i<lim;i++)
	{
		f[u][i][0]=submod(f[u][i][0]-f[u][i][1]);
		f[u][i][1]=submod(f[u][i][1]-1);
	}
//	printf("u=%d\n",u);
//	for(int i=0;i<lim;i++)
//		printf("u=%d,i=%d,f=%d,%d\n",u,i,f[u][i][0],f[u][i][1]);
}
void dfs2(int u,int fa,int dep)
{
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u,dep+1);
	}
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
	dfs2(1,0,1);
	for(int i=1;i<=n;i++)
	{
		lim=i;
		dfs(1,0);
		for(int j=0;j<lim;j++)
			a[i-1]=addmod(a[i-1]+f[1][j][0]);
	}
	for(int i=n-1;i>0;i--)
		a[i]=submod(a[i]-a[i-1]);
	int ans=n;
	for(int i=0;i<n;i++)
	{
	//	printf("i=%d,a=%d\n",i,a[i]);
		ans=addmod(ans+1ll*a[i]*(i-1+mod)%mod);
	}
	ans=1ll*ans*fpow(2,mod-1-n)%mod;
	printf("%d\n",ans);
	return 0;
}