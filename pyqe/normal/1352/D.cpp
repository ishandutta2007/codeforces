#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[2];

int main()
{
	long long t,rr,i,ii,u,p[2],sm[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
			sq[ii]=0;
		}
		p[0]=1;
		p[1]=n;
		z=0;
		for(ii=0;p[0]<=p[1];ii^=1,z++)
		{
			u=!ii*2-1;
			sm[ii]=0;
			for(;sm[ii]<=sm[!ii]&&p[0]<=p[1];p[ii]+=u)
			{
				sm[ii]+=a[p[ii]];
			}
			sq[ii]+=sm[ii];
		}
		printf("%lld %lld %lld\n",z,sq[0],sq[1]);
	}
}