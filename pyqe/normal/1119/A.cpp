#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

int main()
{
	long long i,ii,u,p[2],z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(p[ii]=1+(n-1)*ii;a[p[ii]]==a[1+(n-1)*!ii];p[ii]+=u);
		z=max(z,abs(1+(n-1)*!ii-p[ii]));
	}
	printf("%lld\n",z);
}