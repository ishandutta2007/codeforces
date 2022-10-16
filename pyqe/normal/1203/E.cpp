#include <bits/stdc++.h>

using namespace std;

long long n,a[150069];

int main()
{
	long long i,k,ls=-1e18,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=max(max(a[i]-1,ls+1),1ll);
		if(k<=a[i]+1)
		{
			z++;
			ls=k;
		}
	}
	printf("%lld\n",z);
}