#include <bits/stdc++.h>

using namespace std;

long long n[2],d[2];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",n+ii,d+ii);
		}
		if(d[0]>d[1])
		{
			if(d[0]-d[1]>9)
			{
				printf(">\n");
				continue;
			}
			for(i=0;i<d[0]-d[1];i++)
			{
				n[0]*=10;
			}
		}
		else
		{
			if(d[1]-d[0]>9)
			{
				printf("<\n");
				continue;
			}
			for(i=0;i<d[1]-d[0];i++)
			{
				n[1]*=10;
			}
		}
		if(n[0]<n[1])
		{
			printf("<");
		}
		else if(n[0]>n[1])
		{
			printf(">");
		}
		else
		{
			printf("=");
		}
		printf("\n");
	}
}