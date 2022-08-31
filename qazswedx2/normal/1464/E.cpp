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
}e[500005];
int n,m,h[100005],t,deg[100005],q[100005],head,tail;
int b[100005],bt,vis[100005],a[100005],f[200005],lim=1;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void fwt()
{
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
			{
				int x=f[i+j],y=f[i+j+k];
				f[i+j]=addmod(x+y);
				f[i+j+k]=submod(x-y);
			}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		deg[v]++;
	}
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
	for(int i=n;i>=1;i--)
	{
		int u=q[i];
		bt=0;
		for(int j=h[u];j;j=e[j].nxt)
		{
			int v=e[j].v;
			b[++bt]=a[v];
		}
		for(int j=0;j<=bt+1;j++)
			vis[j]=0;
		for(int j=1;j<=bt;j++)
			vis[b[j]]++;
		a[u]=0;
		while(vis[a[u]]) a[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		f[a[i]]++;
	//	printf("i=%d,a=%d\n",i,a[i]);
	}
	while(lim<=n) lim<<=1;
	fwt();
	int inv=fpow(n+1,mod-2),ans=0;
	for(int i=0;i<lim;i++)
	{
		int p=1ll*f[i]*inv%mod;
		ans=addmod(ans+fpow(submod(1-p),mod-2));
	//	printf("i=%d,f=%d\n",i,f[i]);
	}
	ans=1ll*ans*inv%mod*fpow(lim,mod-2)%mod;
	ans=submod(1-ans);
	printf("%d\n",ans);
	return 0;
}