#include <bits/stdc++.h>

using namespace std;

long long n,sq[1069][1069];

int main()
{
	long long i,j,lh,rh,md,zz,c=0;
	
	scanf("%lld",&n);
	for(lh=1,rh=1e9;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*(md-1)/2<=n)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	for(i=1;i<=zz;i++)
	{
		for(j=i;j<=zz-1;j++)
		{
			c++;
			sq[i][j]=c;
			sq[j+1][i]=c;
		}
	}
	printf("%lld\n",zz);
	for(i=1;i<=zz;i++)
	{
		for(j=1;j<=zz-1;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==zz-1]);
		}
	}
}