#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> fq;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fq.clear();
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z+=fq[k]*(n+1-i);
			fq[k]+=i;
		}
		printf("%lld\n",z);
	}
}