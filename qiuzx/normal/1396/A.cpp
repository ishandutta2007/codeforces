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
ll n,a[N];
vector<ll> md;
int main(){
	ll i,mr;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>=0)
		{
			md.push_back(n-a[i]%n);
		}
		else
		{
			md.push_back(abs(a[i])%n);
		}
	}
	if(n==1)
	{
		puts("1 1");
		printf("%lld\n",-a[0]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	printf("%lld %lld\n",(ll)1,n-1);
	for(i=0;i+1<n;i++)
	{
		printf("%lld ",(n-1)*(n+n-md[i]));
		a[i]+=(n-1)*(n+n-md[i]);
	}
	puts("");
	printf("%lld %lld\n",n,n);
	printf("%lld\n",md[n-1]);
	a[n-1]+=md[n-1];
	printf("%lld %lld\n",(ll)1,n);
	for(i=0;i<n;i++)
	{
		printf("%lld ",-a[i]);
	}
	puts("");
	return 0;
}