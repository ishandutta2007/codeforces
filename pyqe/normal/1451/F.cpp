#include <bits/stdc++.h>

using namespace std;

long long n,m,xr[269];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=2;i<=n+m;i++)
		{
			xr[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&k);
				xr[i+j]^=k;
			}
		}
		for(i=2;i<=n+m;i++)
		{
			if(xr[i])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("Ashish\n");
		}
		else
		{
			printf("Jeel\n");
		}
	}
}