#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,k,c,z=0,l=0;
	
	scanf("%lld%lld",&n,&c);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k-l>c)
		{
			z=0;
		}
		z++;
		l=k;
	}
	printf("%lld\n",z);
}