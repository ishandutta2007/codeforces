#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[100069],v[100069];
pair<long long,long long> a[100069];

int main()
{
	long long i,b=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		v[i]=a[i].fr;
	}
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[max((long long)(lower_bound(v,v+n+1,v[i]-a[i].sc)-v-1),(long long)0)]+1;
		b=max(b,dp[i]);
	}
	printf("%lld\n",n-b);
}