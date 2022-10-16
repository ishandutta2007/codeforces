#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],ps[2][100069];

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i]=ps[ii][i-1]+a[i]*(k||ii);
		}
	}
	for(i=d;i<=n;i++)
	{
		z=max(z,ps[0][i-d]+ps[1][i]-ps[1][i-d]+ps[0][n]-ps[0][i]);
	}
	printf("%lld\n",z);
}