#include <bits/stdc++.h>

using namespace std;

long long n,fqq[200069],inf=1e18;
map<long long,long long> fq;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fq.clear();
		for(i=1;i<=n;i++)
		{
			fqq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
			fqq[fq[k]]++;
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			z=min(z,n-i*fqq[i]);
		}
		printf("%lld\n",z);
	}
}