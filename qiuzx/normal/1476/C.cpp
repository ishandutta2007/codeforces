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
#define N 100010
using namespace std;
ll n,sz[N],a[N],b[N],ans;
pair<ll,ll> cn[N];
int main(){
	ll t,i,j,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&sz[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			cn[i]=make_pair(min(a[i],b[i]),max(a[i],b[i]));
		}
		ans=0;
		sum=sz[n-1]-1;
		for(i=n-2;i>=0;i--)
		{
			sum+=2;
			if(cn[i+1].S==cn[i+1].F)
			{
				ans=max(ans,sum);
				sum=sz[i]-1;
			}
			else
			{
				ans=max(ans,sum+cn[i+1].S-cn[i+1].F);
				sum+=sz[i]-cn[i+1].S+cn[i+1].F-1;
				sum=max(sum,sz[i]-1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}