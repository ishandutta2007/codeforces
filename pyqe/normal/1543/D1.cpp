#include <bits/stdc++.h>

using namespace std;

const long long ub=18;
long long n,d,ca[ub],lz[ub];

int main()
{
	long long t,rr,i,j,u,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<ub;i++)
		{
			lz[i]=0;
		}
		u=1;
		for(i=0;i<n;i++)
		{
			for(j=0,k=i;j<ub;k/=d,j++)
			{
				ca[j]=(k%d*u+d+lz[j])%d;
			}
			z=0;
			for(j=ub-1;j+1;j--)
			{
				z=z*d+ca[j];
			}
			printf("%lld\n",z);
			fflush(stdout);
			scanf("%lld",&k);
			if(k)
			{
				break;
			}
			for(j=0;j<ub;j++)
			{
				lz[j]=(ca[j]+d-lz[j])%d;
			}
			u*=-1;
		}
	}
}