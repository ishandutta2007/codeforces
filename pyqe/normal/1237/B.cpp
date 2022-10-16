#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pst[100069];

int main()
{
	long long i,k,mx=-1e18,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(pst[a[i]]<mx)
		{
			z++;
		}
		mx=max(mx,pst[a[i]]);
	}
	printf("%lld\n",z);
}