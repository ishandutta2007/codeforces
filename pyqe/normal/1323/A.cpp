#include <bits/stdc++.h>

using namespace std;

long long n,sq[2][100069],zs[2];

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			zs[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			zs[k%2]++;
			sq[k%2][zs[k%2]]=i;
		}
		for(ii=0;ii<2;ii++)
		{
			if(zs[ii]>=1+ii)
			{
				printf("%lld\n",1+ii);
				for(i=1;i<=1+ii;i++)
				{
					printf("%lld%c",sq[ii][i]," \n"[i==1+ii]);
				}
				ii=-1;
				break;
			}
		}
		if(ii!=-1)
		{
			printf("-1\n");
		}
	}
}