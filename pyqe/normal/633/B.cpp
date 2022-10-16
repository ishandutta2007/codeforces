#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,lh,rh,md,sm;
	
	scanf("%lld",&n);
	for(lh=1,rh=1e5;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(k=md*5;k;k/=5,sm+=k);
		if(sm==n)
		{
			printf("5\n");
			for(i=0;i<5;i++)
			{
				printf("%lld%c",md*5+i," \n"[i==4]);
			}
			return 0;
		}
		else if(sm>n)
		{
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("0\n");
}