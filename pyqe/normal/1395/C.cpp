#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][269];

int main()
{
	long long i,j,r,ii,w,z=0;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=8;i+1;i--)
	{
		w=z|(1ll<<i)-1;
		for(j=1;j<=n[0];j++)
		{
			for(r=1;r<=n[1];r++)
			{
				if(((a[0][j]&a[1][r])|w)==w)
				{
					r=-1;
					break;
				}
			}
			if(r!=-1)
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			z|=1ll<<i;
		}
	}
	printf("%lld\n",z);
}