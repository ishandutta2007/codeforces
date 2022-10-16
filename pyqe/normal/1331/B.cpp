#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			for(;n%i==0;n/=i)
			{
				printf("%lld",i);
			}
		}
	}
	if(n>1)
	{
		printf("%lld",n);
	}
	printf("\n");
}