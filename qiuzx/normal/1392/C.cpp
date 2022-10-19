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
#define N 200010
using namespace std;
ll n,a[N];
int main(){
	ll T,i,mx,ans,tmx;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ans=0;
		for(i=1;i<n;i++)
		{
			ans+=max((ll)0,a[i-1]-a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}