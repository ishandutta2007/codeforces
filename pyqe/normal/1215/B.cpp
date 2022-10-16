#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> a;

int main()
{
	long long i,z=0,l=0,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k>0)
		{
			a[i]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			k=l+1;
		}
		else
		{
			k=i-l-1;
		}
		z+=k;
		l=k;
	}
	printf("%lld %lld\n",n*(n+1)/2-z,z);
}