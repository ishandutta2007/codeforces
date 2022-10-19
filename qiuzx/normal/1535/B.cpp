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
#define N 2010
using namespace std;
ll T,n,a[N],ans;
vector<ll> v;
int main(){
	ll i,j;
	scanf("%lld",&T);
	while(T--)
	{
		v.clear();
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]%2==0)
			{
				v.push_back(a[i]);
			}
		}
		for(i=0;i<n;i++)
		{
			if(a[i]%2!=0)
			{
				v.push_back(a[i]);
			}
		}
		ans=0;
		for(i=0;i<v.size();i++)
		{
			for(j=i+1;j<v.size();j++)
			{
				if(__gcd(v[i],2*v[j])>1)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}