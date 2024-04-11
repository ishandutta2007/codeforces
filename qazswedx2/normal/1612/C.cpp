#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
int T;
ll check(ll x)
{
	if(x<=n) return 1ll*x*(x+1)/2;
	else return 1ll*n*(n+1)/2+1ll*(3*n-x-1)*(x-n)/2;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		ll l=1,r=2*n-1;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(mid)<m) l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",min(l,2*n-1));
	}
	return 0;
}