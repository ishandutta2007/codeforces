#include <bits/stdc++.h>

using namespace std;

long long ln,n,ft[100069],ls[100069];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld",&ln,&n);
	for(i=1;i<=ln;i++)
	{
		ft[i]=1e18;
		ls[i]=-1e18;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ft[k]=min(ft[k],i);
		ls[k]=i;
	}
	for(i=1;i<=ln;i++)
	{
		for(j=max(i-1,1ll);j<=min(i+1,ln);j++)
		{
			z+=ft[i]>ls[j];
		}
	}
	printf("%lld\n",z);
}