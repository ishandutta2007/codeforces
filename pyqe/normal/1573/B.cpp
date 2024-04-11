#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[2][100069],pn[200069];

int main()
{
	long long t,rr,i,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			pn[a[0][i]]=i-1;
		}
		for(i=3;i<=n*2;i+=2)
		{
			pn[i]=min(pn[i],pn[i-2]);
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			z=min(z,i-1+pn[a[1][i]-1]);
		}
		printf("%lld\n",z);
	}
}