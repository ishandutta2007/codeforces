#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],ll[1069];
bitset<1069> vtd,sq[1069];

int main()
{
	long long i,j,ls;
	bool ft;
	
	scanf("%lld",&n);
	vtd[0]=1;
	vtd[n+1]=1;
	for(i=1;i<=n+1;i++)
	{
		ll[i]=1e18;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ft=1;
		ls=0;
		for(j=1;j<=n+1;j++)
		{
			if(ll[j]>i&&a[i])
			{
				if(!ft||!vtd[j])
				{
					sq[i][j]=1;
					a[i]--;
					ls=j;
				}
				else
				{
					ft=0;
					ll[j]=i;
					vtd[j-1]=1;
					if(vtd[j-2])
					{
						ll[j-1]=i;
					}
				}
			}
		}
		for(j=1;j<=n+1;j++)
		{
			if(ll[j]<i&&a[i])
			{
				sq[i][j]=1;
				a[i]--;
			}
		}
		if(ls)
		{
			vtd[ls]=1;
			if(vtd[ls-1])
			{
				ll[ls]=i;
			}
			if(vtd[ls+1]&&ll[ls+1]>i)
			{
				ll[ls+1]=i;
			}
		}
	}
	printf("%lld\n",n+1);
	for(j=1;j<=n+1;j++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",(bool)sq[i][j]);
		}
		printf("\n");
	}
}