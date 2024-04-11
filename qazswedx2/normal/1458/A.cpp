#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll a[1000005],b[1000005];
ll gcd(ll x,ll y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
ll F(ll x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	ll g=0;
	for(int i=1;i<n;i++)
		g=gcd(g,F(a[i+1]-a[i]));
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",gcd(g,a[1]+b[i]));
	}
	return 0;
}