#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs;
pair<long long,long long> aa[100069],a[100069],sq[100069];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&aa[i].fr);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&aa[i].sc);
			a[i]=aa[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<n;i++)
		{
			if(a[i].sc>a[i+1].sc)
			{
				break;
			}
		}
		if(i<n)
		{
			printf("-1\n");
			continue;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;aa[j]!=a[i];j++);
			if(j!=i)
			{
				zs++;
				sq[zs]={i,j};
				swap(aa[i],aa[j]);
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr,sq[i].sc);
		}
	}
}