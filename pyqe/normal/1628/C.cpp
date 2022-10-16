#include <bits/stdc++.h>

using namespace std;

long long n,a[1069][1069];

int main()
{
	long long t,rr,i,j,ii,y,x,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if((i+j)%4==2)
					{
						y=i+j-1;
						x=1;
						if(y>n)
						{
							x+=y-n;
							y=n;
						}
						if(i%2==y%2&&j%2==x%2)
						{
							z^=a[i][j];
						}
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<n+1-j;j++)
				{
					swap(a[i][j],a[i][n+1-j]);
				}
			}
		}
		printf("%lld\n",z);
	}
}