#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],inf=1e18;

int main()
{
	long long i,ii,iii,k,st,df,sm,z=inf;
	
	scanf("%lld",&n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=-1;ii<=1;ii++)
	{
		for(iii=-1;iii<=1;iii++)
		{
			df=a[2]+iii-a[1]-ii;
			st=a[1]+ii-df;
			sm=0;
			for(i=1;i<=n;i++)
			{
				k=abs(st+df*i-a[i]);
				if(k>1)
				{
					i=-1;
					break;
				}
				sm+=k;
			}
			if(i!=-1)
			{
				z=min(z,sm);
			}
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}