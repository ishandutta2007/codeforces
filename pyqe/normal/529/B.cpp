#include <bits/stdc++.h>

using namespace std;

long long n,nn,ma=1000,a[1069],wg[1069],as[1069],inf=1e18;

int main()
{
	long long i,j,sm,c,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,wg+i);
	}
	for(i=1;i<=ma;i++)
	{
		sm=0;
		c=0;
		nn=0;
		for(j=1;j<=n;j++)
		{
			if(a[j]>i)
			{
				if(wg[j]>i)
				{
					j=-1;
					break;
				}
				else
				{
					sm+=a[j];
				}
			}
			else
			{
				if(wg[j]>i)
				{
					sm+=wg[j];
					c++;
				}
				else
				{
					sm+=a[j];
					nn++;
					as[nn]=wg[j]-a[j];
				}
			}
		}
		if(j==-1||c>n/2)
		{
			continue;
		}
		sort(as+1,as+nn+1);
		for(j=1;j<=min(nn,n/2-c)&&as[j]<0;j++)
		{
			sm+=as[j];
		}
		z=min(z,sm*i);
	}
	printf("%lld\n",z);
}