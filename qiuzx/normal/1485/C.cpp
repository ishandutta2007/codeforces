#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll x,y,ans;
ll bord(ll a)
{
	ll l=0,r=LINF,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(a/(mid+1)>mid-1)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return l;
}
int main(){
	ll T,mx,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		ans=0;
		mx=bord(x);
		mx=min(mx,y);
		for(i=1;i<=mx;i++)
		{
			ans+=i*max((ll)0,min(x/i,y+1)-max(x/(i+1),mx+1));
		}
		printf("%lld\n",ans+mx*(mx-1)/2);
	}
	return 0;
}