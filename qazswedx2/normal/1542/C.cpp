#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
int t,m=42;
ll n,a[105];
int main()
{
	a[1]=1;
	for(int i=2;i<=m;i++)
		a[i]=lcm(a[i-1],i);
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%lld",&n);
		ans=n%mod;
		for(int i=1;i<=m;i++)
			ans=(ans+n/a[i])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}