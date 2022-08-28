#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,st[100005],tp;
ll c[100005],a[100005],d[100005],f[100005],g[100005],st2[100005];
bool cmp(const ll x,const ll y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	d[0]=d[n+1]=1e18;
	tp=1;
	st[1]=0;
	for(int i=1;i<=n+1;i++)
	{
		while(tp&&2ll*d[st[tp]]+f[st[tp]]<a[i]) tp--;
		if(2*d[i]>(a[i]-a[st[tp]]))
			f[i]=a[st[tp]];
		else f[i]=-1e18;
		while(tp&&2ll*d[i]+f[i]>=2ll*d[st[tp]]+f[st[tp]]) tp--;
		st[++tp]=i;
	}
	if(f[n+1]!=0)
	{
		printf("0\n");
		return 0;
	}
	tp=1;
	st[1]=n+1;
	for(int i=n;i>0;i--)
	{
		while(tp&&g[st[tp]]-2*d[st[tp]]>a[i]) tp--;
		if(2*d[i]>(a[st[tp]]-a[i]))
			g[i]=a[st[tp]];
		else g[i]=1e18;
		while(tp&&g[i]-2*f[i]<=g[st[tp]]-2*d[st[tp]]) tp--;
		st[++tp]=i;
	}
	for(int i=0;i<=n;i++)
		c[i]=2*d[i]-(a[i]-f[i]);
//	for(int i=1;i<=n;i++)
//		printf("i=%d,c=%lld,f=%lld,g=%lld\n",i,c[i],f[i],g[i]);
	tp=1;
	st[1]=0;
	st2[1]=1e18;
	ll ans=a[n+1];
	for(int i=1;i<=n+1;i++)
	{
		ll nw=2*d[i]-(g[i]-a[i]);
		if(nw>0)
		{
		//	printf("i=%d,nw=%lld\n",i,nw);
			int l=upper_bound(st2+1,st2+tp+1,a[i]-nw,cmp)-st2-1;
		//	printf("l=%d,tp=%d\n",l,tp);
			ans=min(ans,a[i]-a[st[l]]);
		}
		if(c[i]>0)
		{
			while(tp&&c[i]+a[i]>=st2[tp]) tp--;
			st[++tp]=i;
			st2[tp]=c[i]+a[i];
		}
	}
	printf("%f\n",ans/2.0);
	return 0;
}