#include <bits/stdc++.h>

using namespace std;

const long long ub=200,inf=1e18;
long long n,d,a[100069];

int main()
{
	long long t,rr,i,j,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=-inf;
		for(i=1;i<=min(ub,n);i++)
		{
			for(j=i+1;j<=min(ub,n);j++)
			{
				k=n+1-i;
				l=n+1-j;
				z=max(z,k*l-d*(a[k]|a[l]));
			}
		}
		printf("%lld\n",z);
	}
}