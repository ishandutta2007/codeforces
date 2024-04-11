#include <bits/stdc++.h>

using namespace std;

long long n,fq[2],sq[1069],zs;

int main()
{
	long long t,rr,i,ii,jj,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
			if(i%4==0||i==n)
			{
				for(ii=0;ii<2;ii++)
				{
					if(fq[ii]>=2)
					{
						for(jj=0;jj<2;jj++)
						{
							zs++;
							sq[zs]=ii;
						}
						ii=-1;
						break;
					}
				}
				if(ii!=-1)
				{
					zs++;
					sq[zs]=0;
				}
				for(ii=0;ii<2;ii++)
				{
					fq[ii]=0;
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}