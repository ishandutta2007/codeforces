#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[200005],t,a[200005],b[200005];
ll f[200005][2],tans=1e18;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	int ct0=0,ct1=0;
	ll ans=0;
	vector<ll> val;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		if(a[u]!=a[v])
		{
			if(a[u]<a[v]) ct0++,ans+=f[v][0];
			if(a[u]>a[v]) ct1++,ans+=f[v][1];
			continue;
		}
		ct0++;
		ans+=f[v][0];
		val.push_back(f[v][1]-f[v][0]);
	}
	sort(val.begin(),val.end());
	int sz=val.size();
	f[u][0]=f[u][1]=1e18;
	for(int i=0;i<=sz;i++)
	{
		f[u][0]=min(f[u][0],1ll*max(ct1+1,ct0)*b[u]+ans);
		f[u][1]=min(f[u][1],1ll*max(ct1,ct0+1)*b[u]+ans);
		if(u==1) tans=min(tans,1ll*max(ct0,ct1)*b[u]+ans);
		if(i==sz) break;
		ans+=val[i];
		ct1++,ct0--;
	}
//	printf("u=%d,f=%lld,%lld\n",u,f[u][0],f[u][1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",tans);
	return 0;
}