#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].fr);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].sc);
		}
		sort(a+1,a+n+1,greater<pair<long long,long long>>());
		a[n+1].fr=0;
		z=inf;
		sm=0;
		for(i=0;i<=n;i++)
		{
			sm+=a[i].sc;
			z=min(z,max(a[i+1].fr,sm));
		}
		printf("%lld\n",z);
	}
}