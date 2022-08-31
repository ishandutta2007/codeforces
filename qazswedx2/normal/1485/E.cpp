#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int tt,n,a[200005],f[200005],h[200005],t,d[200005],dfn[200005],udfn[200005],mx[200005],ct;
ll dp[200005],lazymx[200005],lazymn[200005];
int q[200005],head,tail,mn[200005],fir[200005],ft;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		t=ct=0;
		for(int i=1;i<=n;i++)
		{
			h[i]=mx[i]=dp[i]=0,mn[i]=1e9;
			dp[i]=0;
			lazymx[i]=lazymn[i]=-1e18;
		}
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&f[i]);
			add(f[i],i),add(i,f[i]);
		}
		for(int i=2;i<=n;i++)
			scanf("%d",&a[i]);
		d[1]=0;
		head=0,tail=1;
		q[1]=1;
		dfn[1]=++ct;
		udfn[ct]=1;
		while(head<tail)
		{
			head++;
			int u=q[head];
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(v==f[u]) continue;
				d[v]=d[u]+1;
				dfn[v]=++ct;
				udfn[ct]=v;
				mx[d[v]]=max(mx[d[v]],a[v]);
				mn[d[v]]=min(mn[d[v]],a[v]);
				q[++tail]=v;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int u=udfn[i],l=d[u];
			dp[u]=max(dp[u],max(lazymx[l]-a[u],lazymn[l]+a[u]));
			ans=max(ans,dp[u]);
		//	printf("u=%d,l=%d,dp=%lld\n",u,l,dp[u]);
			if(l==d[udfn[n]]) continue;
			int nw0=0,nw1=1e9;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				if(v==f[u]) continue;
				dp[v]=max(dp[v],dp[u]+max(a[v]-mn[l+1],mx[l+1]-a[v]));
				nw0=max(nw0,a[v]);
				nw1=min(nw1,a[v]);
			}
			lazymx[l+1]=max(lazymx[l+1],dp[u]+nw0);
			lazymn[l+1]=max(lazymn[l+1],dp[u]-nw1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}