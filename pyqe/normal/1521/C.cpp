#include <bits/stdc++.h>

using namespace std;

long long n,sq[10069];

int main()
{
	long long t,rr,i,k,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(zz=n,lh=1,rh=n-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			printf("? 2 1 2 %lld\n",md);
			fflush(stdout);
			scanf("%lld",&k);
			if(k==md)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		sq[1]=zz;
		for(i=2;i<=n;i++)
		{
			if(sq[1]>n/2)
			{
				printf("? 2 %lld 1 1\n",i);
			}
			else
			{
				printf("? 1 1 %lld %lld\n",i,n-1);
			}
			fflush(stdout);
			scanf("%lld",&k);
			if(k==sq[1])
			{
				if(sq[1]>n/2)
				{
					printf("? 1 1 %lld %lld\n",i,n-1);
				}
				else
				{
					printf("? 2 %lld 1 1\n",i);
				}
				fflush(stdout);
				scanf("%lld",&k);
			}
			sq[i]=k;
		}
		printf("!");
		for(i=1;i<=n;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}