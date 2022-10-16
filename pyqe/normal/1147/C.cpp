#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,mn=1e18,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		mn=min(mn,a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==mn)
		{
			z++;
		}
	}
	if(z<=n/2)
	{
		printf("Alice\n");
	}
	else
	{
		printf("Bob\n");
	}
}