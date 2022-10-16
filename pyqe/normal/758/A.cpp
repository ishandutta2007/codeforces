#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k,b=0,z=0,i;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k>b)
		{
			z+=(k-b)*i;
			b=k;
		}
		z+=b-k;
	}
	printf("%lld\n",z);
}