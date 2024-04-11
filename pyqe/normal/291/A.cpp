#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> fq;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k)
		{
			fq[k]++;
			if(fq[k]>2)
			{
				printf("-1\n");
				return 0;
			}
			z+=fq[k]==2;
		}
	}
	printf("%lld\n",z);
}