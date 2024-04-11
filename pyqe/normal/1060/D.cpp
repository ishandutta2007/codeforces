#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long i,ii,z;
	
	scanf("%lld",&n);
	z=n;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+n+1);
	}
	for(i=1;i<=n;i++)
	{
		z+=max(a[0][i],a[1][i]);
	}
	printf("%lld\n",z);
}