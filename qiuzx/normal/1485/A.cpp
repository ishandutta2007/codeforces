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
ll a,b,ans;
int main(){
	ll T,i,x,ts;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		ans=LINF;
		for(i=b;i-b<ans;i++)
		{
			if(i==1)
			{
				continue;
			}
			ts=i-b;
			x=a;
			while(x>0)
			{
				x/=i;
				ts++;
			}
			ans=min(ans,ts);
		}
		printf("%lld\n",ans);
	}
	return 0;
}