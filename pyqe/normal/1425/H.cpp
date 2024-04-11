#include <bits/stdc++.h>

using namespace std;

long long a[2];

int main()
{
	long long t,rr,i,ii,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			a[ii]=0;
		}
		sm=0;
		for(i=0;i<4;i++)
		{
			scanf("%lld",&k);
			a[min(i,3-i)]+=k;
			sm+=k*(i<3-i);
		}
		for(i=0;i<4;i++)
		{
			if(3-i<i^sm%2)
			{
				if(a[min(i,3-i)])
				{
					printf("Ya");
				}
				else
				{
					printf("Tidak");
				}
			}
			else
			{
				printf("Tidak");
			}
			printf("%c"," \n"[i==3]);
		}
	}
}