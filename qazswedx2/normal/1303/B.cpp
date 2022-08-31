#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
ll n,g,b;
bool check(ll x)
{
	ll gt=x/(b+g)*g+min(x%(b+g),g),bt=x/(b+g)*b+max(x%(b+g)-g,0ll);
	return gt+min(gt,bt)>=n;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&g,&b);
		ll l=0,r=1e18;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",l);
		/*ll m=g+b,nw=g+min(g,b);
		if(n<=nw)
		{
			printf("%d\n",n);
			continue;
		}
		ll ans=0;
		ans=1ll*(n/nw-(n%nw==0))*m;
		ll p=n%nw;
		if(!p) p=nw;
		//printf("ans=%lld,p=%lld\n",ans,p);
		if(p<=g) ans+=p;
		else
		{
			ll tnw=1ll*(n/nw-(n%nw==0))*max(0,b-g);
			ans+=max((ll)g,p-tnw);
		}
		printf("%lld\n",ans);*/
	}
	return 0;
}