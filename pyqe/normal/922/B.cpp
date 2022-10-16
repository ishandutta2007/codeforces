#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			z+=(i^j)<=n&&j<=(i^j)&&i+j>(i^j);
		}
	}
	printf("%lld\n",z);
}