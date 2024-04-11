#include <bits/stdc++.h>

using namespace std;

long long n,d,dd,a[100069];
map<long long,bool> vtd;
map<long long,long long> fq;

int main()
{
	long long i,sm,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(dd=1;1;dd*=d)
	{
		if(abs(dd)>100000000000000||vtd[dd])
		{
			break;
		}
		vtd[dd]=1;
		fq.clear();
		sm=0;
		fq[0]++;
		for(i=1;i<=n;i++)
		{
			sm+=a[i];
			z+=fq[sm-dd];
			fq[sm]++;
		}
	}
	printf("%lld\n",z);
}