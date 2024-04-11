#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n;
ll k,a[1000005];
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		ll g=0;
		for(int i=2;i<=n;i++)
			g=gcd(g,a[i]-a[i-1]);
		if((k-a[1])%g==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}