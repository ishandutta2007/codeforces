#include <bits/stdc++.h>

using namespace std;

long long ln,n,d;

int main()
{
	long long i,k,l,c=0,z=0;
	
	scanf("%lld%lld%lld",&ln,&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(i-1&&(k-c-1)/d+1!=(l-c-1)/d+1)
		{
			c=i-1;
			z++;
		}
		l=k;
	}
	z+=c!=n;
	printf("%lld\n",z);
}