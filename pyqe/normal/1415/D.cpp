#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[30],inf=1e18;

int main()
{
	long long i,j,r,k,c,xr,xr2,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(c=0,k=a[i];k>1;k/=2,c++);
		fq[c]++;
		if(fq[c]==3)
		{
			printf("1\n");
			return 0;
		}
	}
	z=inf;
	for(i=0;i<=n;i++)
	{
		xr=0;
		for(j=i+1;j<=n;j++)
		{
			xr^=a[j];
			xr2=0;
			for(r=j+1;r<=n;r++)
			{
				xr2^=a[r];
				if(xr>xr2)
				{
					z=min(z,j-i-1+r-j-1);
				}
			}
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}