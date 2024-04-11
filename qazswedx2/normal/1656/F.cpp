#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n;
ll a[2000005],ans;
void upd(ll k,ll b,ll l,ll r)
{
	ans=max(ans,k*l+b);
	ans=max(ans,k*r+b);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=-1e18;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		ll sum=0,nw=0;
		for(int i=1;i<=n;i++)
			nw+=a[i];
		for(int i=2;i<=n;i++)
			sum+=1ll*a[1]*a[i];
		int fl=0;
		for(int i=1;i<n;i++)
		{
			ll k=nw+1ll*(n-i-1)*a[1]+1ll*(i-1)*a[n];
			k=-k;
			upd(k,sum,a[i],a[i+1]);
			if(k<0&&i==1) fl=1;
			if(k>0&&i==n-1) fl=1;
			sum=sum-1ll*a[1]*a[i+1]+1ll*a[n]*a[i+1]; 
		}
		if(fl) printf("INF\n");
		else printf("%lld\n",ans);
	}
}