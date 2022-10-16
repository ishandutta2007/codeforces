#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	double lh,rh,md;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n>0&&n<4)
		{
			printf("N\n");
			continue;
		}
		lh=(double)n/2;
		rh=n;
		md=n;
		for(;lh+1e-12<=rh;)
		{
			md=(lh+rh)/2;
			if(md*(n-md)>=n)
			{
				lh=md;
			}
			else
			{
				rh=md;
			}
		}
		printf("Y %.18lf %.18lf\n",md,n-md);
	}
}