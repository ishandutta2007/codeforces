#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,c,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c=0;
		for(;k;k/=10)
		{
			c+=k%10==4||k%10==7;
		}
		z+=c<=d;
	}
	printf("%lld\n",z);
}