#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> ls;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z+=ls[k]<rr;
			ls[k]=rr;
		}
		printf("%lld\n",z);
	}
}