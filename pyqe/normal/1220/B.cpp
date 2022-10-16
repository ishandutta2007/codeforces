#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long i,j,k,dn,w,lh=1,rh=1e9,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			if(i==1)
			{
				a[j]=k;
			}
			else if(i==2&&j==3)
			{
				dn=k;
			}
		}
	}
	w=a[2]*a[3]/dn;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*md<=w)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld",zz);
	for(i=2;i<=n;i++)
	{
		printf(" %lld",a[i]/zz);
	}
	printf("\n");
}