#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,ps[2][100069];

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
				scanf("%lld",&ps[ii][i]);
				ps[ii][i]+=ps[ii][i-1];
			}
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			z=min(z,max(ps[1][i-1],ps[0][n]-ps[0][i]));
		}
		printf("%lld\n",z);
	}
}