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
#define N 510
using namespace std;
ll n,k,ans;
vector<ll> a;
bool sord()
{
	vector<ll> t=a;
	sort(t.begin(),t.end());
	return (t==a);
}
int main(){
	ll t,i,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		a.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a.push_back(x);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			if(sord())
			{
				break;
			}
			if(a[i]>k)
			{
				swap(a[i],k);
				ans++;
			}
		}
		if(sord())
		{
			printf("%lld\n",ans);
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}