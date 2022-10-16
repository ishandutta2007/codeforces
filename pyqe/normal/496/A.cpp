#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[100069],df[100069],px[2][100069];

int main()
{
	long long i,ii,u,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	n--;
	for(i=1;i<=n;i++)
	{
		df[i]=a[i+1]-a[i];
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			px[ii][i]=max(px[ii][i-u],df[i]);
		}
	}
	for(i=1;i<n;i++)
	{
		z=min(z,max(max(px[0][i-1],px[1][i+2]),df[i]+df[i+1]));
	}
	printf("%lld\n",z);
}