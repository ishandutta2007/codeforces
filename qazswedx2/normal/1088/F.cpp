#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[2000005];
int n,a[1000005],h[1000005],t,c[1000005][22],f[1000005][22];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	c[u][0]=fa;
	f[u][0]=a[u];
	for(int i=1;i<=19;i++)
	{
		c[u][i]=c[c[u][i-1]][i-1];
		f[u][i]=min(f[u][i-1],f[c[u][i-1]][i-1]);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	int mn=1e9+100,rt=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<mn) mn=a[i],rt=i;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(rt,0);
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(i!=rt)
		{
			ans+=a[i];
			int v=c[i][1];
			ll nw=a[c[i][0]];
			for(int j=0;j<19;j++)
			{
				if(!v) break;
				nw=min(nw,1ll*(j+2)*f[v][j]);
				v=c[v][j];
			}
		//	printf("i=%d,nw=%lld\n",i,nw);
			ans+=nw;
		}
	printf("%lld\n",ans);
	return 0;
}