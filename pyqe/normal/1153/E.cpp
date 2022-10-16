#include <bits/stdc++.h>

using namespace std;

long long n,sq[2][2],zs=0;

int main()
{
	long long i,ii,iii,k,y,x,y2,x2,e,lh,rh,md;
	
	scanf("%lld",&n);
	for(ii=0;zs<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			y=i;
			x=1;
			y2=i;
			x2=n;
			if(ii)
			{
				swap(y,x);
				swap(y2,x2);
			}
			printf("? %lld %lld %lld %lld\n",y,x,y2,x2);
			fflush(stdout);
			scanf("%lld",&k);
			if(k%2)
			{
				sq[zs][ii]=i;
				zs++;
			}
		}
		e=ii;
	}
	for(ii=0;ii<=!e;ii++)
	{
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			y=sq[ii][e];
			x=1;
			y2=sq[ii][e];
			x2=md;
			if(e)
			{
				swap(y,x);
				swap(y2,x2);
			}
			printf("? %lld %lld %lld %lld\n",y,x,y2,x2);
			fflush(stdout);
			scanf("%lld",&k);
			if(k%2)
			{
				sq[ii][!e]=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
	}
	if(e)
	{
		sq[1][0]=sq[0][0];
	}
	printf("!");
	for(ii=0;ii<2;ii++)
	{
		for(iii=0;iii<2;iii++)
		{
			printf(" %lld",sq[ii][iii]);
		}
	}
	printf("\n");
	fflush(stdout);
}