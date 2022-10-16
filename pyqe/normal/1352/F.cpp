#include <bits/stdc++.h>

using namespace std;

long long a[3];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<a[ii*2]+(a[ii*2]||a[1]);i++)
			{
				printf("%lld",ii);
			}
		}
		for(i=0;i<a[1]-1;i++)
		{
			printf("%lld",i%2);
		}
		printf("\n");
	}
}