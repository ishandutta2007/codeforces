#include <bits/stdc++.h>

using namespace std;

long long n[2],d[2],sq[200069],zs;
bitset<200069> spc;

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",n+ii);
		}
		d[0]=(n[0]+n[1]+1)/2;
		d[1]=(n[0]+n[1])/2;
		for(i=0;i<=n[0]+n[1];i++)
		{
			spc[i]=0;
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<=min(n[0],d[ii]);i++)
			{
				if(n[0]-i<=d[!ii])
				{
					spc[n[0]-i+d[ii]-i]=1;
				}
			}
		}
		zs=0;
		for(i=0;i<=n[0]+n[1];i++)
		{
			if(spc[i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}