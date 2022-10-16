#include <bits/stdc++.h>

using namespace std;

long long n,a[4],fq[2];

int main()
{
	long long i,j,ii,lh,rh,md;
	bool bad;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<2;i++)
	{
		for(lh=1,rh=1e9;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*(md-1)/2<=a[i*3])
			{
				fq[i]=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		if(fq[i]*(fq[i]-1)/2!=a[i*3])
		{
			printf("Impossible\n");
			return 0;
		}
	}
	bad=1;
	for(i=fq[0]-(fq[0]==1);bad&&i<=fq[0];i++)
	{
		for(j=fq[1];j>=fq[1]-(fq[1]==1);j--)
		{
			if(i*j==a[1]+a[2])
			{
				fq[0]=i;
				fq[1]=j;
				bad=0;
				break;
			}
		}
	}
	if(bad)
	{
		printf("Impossible\n");
		return 0;
	}
	for(ii=0;ii<2;ii++)
	{
		if(!fq[!ii])
		{
			for(i=0;i<fq[ii];i++)
			{
				printf("%lld",ii);
			}
			printf("\n");
			return 0;
		}
	}
	for(i=0;i<a[2]/fq[0];i++)
	{
		printf("1");
	}
	for(i=0;i<fq[0]-a[2]%fq[0];i++)
	{
		printf("0");
	}
	if(fq[1]>a[2]/fq[0])
	{
		printf("1");
	}
	for(i=0;i<a[2]%fq[0];i++)
	{
		printf("0");
	}
	for(i=0;i<fq[1]-a[2]/fq[0]-1;i++)
	{
		printf("1");
	}
	printf("\n");
}