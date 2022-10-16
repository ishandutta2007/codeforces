#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;
pair<long long,long long> a[100069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].fr);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].sc);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			d+=l*(d>=k);
		}
		printf("%lld\n",d);
	}
}