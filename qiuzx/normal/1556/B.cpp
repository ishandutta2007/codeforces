//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,a[N],ans,ans2;
vector<ll> v;
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		v.clear();
		for(i=0;i<n;i++)
		{
			if(a[i]%2==1)
			{
				v.push_back(i);
			}
		}
		if(v.size()!=n/2&&v.size()!=(n+1)/2)
		{
			puts("-1");
			continue;
		}
		ans=ans2=LINF;
		if(v.size()==n/2)
		{
			ans=0;
			for(i=1;i<n;i+=2)
			{
				ans+=abs(i-v[i/2]);
			}
		}
		if(v.size()==(n+1)/2)
		{
			ans2=0;
			for(i=0;i<n;i+=2)
			{
				ans2+=abs(i-v[i/2]);
			}
		}
		printf("%lld\n",min(ans,ans2));
	}
	return 0;
}