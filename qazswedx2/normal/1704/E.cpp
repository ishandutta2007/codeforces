#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[1000005];
int T,n,m,h[100005],t,q[100005],head,tail,deg[100005],f[100005];
ll a[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;i++)
			h[i]=deg[i]=f[i]=0;
		t=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			deg[v]++;
		}
		head=0,tail=0;
		for(int i=1;i<=n;i++)
			if(!deg[i])
				q[++tail]=i;
		while(head<tail)
		{
			head++;
			int u=q[head];
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				deg[v]--;
				if(!deg[v]) q[++tail]=v;
			}
		}
		int nfl=1;
		for(int i=1;i<=n;i++)
		{
			int fl=0;
			for(int j=n;j>0;j--)
			{
				int u=q[j]; 
				if(a[u])
				{
				//	printf("i=%d,j=%d,u=%d,a=%d\n",i,j,u,a[u]); 
					fl=1;
					a[u]--;
					for(int l=h[u];l;l=e[l].nxt)
					{
						int v=e[l].v;
						a[v]++;
					}
				}
			}
			if(!fl)
			{
				printf("%d\n",i-1);
				nfl=0;
				break;
			}
		}
		if(!nfl) continue;
		f[q[n]]=1;
		for(int i=n-1;i>0;i--)
		{
			int u=q[i];
			f[u]=0;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				f[u]=(f[u]+f[v])%mod;
			}
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
		//	printf("i=%d,a=%lld,f=%d\n",i,a[i],f[i]);
			ans=(ans+1ll*a[i]%mod*f[i])%mod;
		}
		printf("%d\n",ans); 
	}
}