#include <bits/stdc++.h>

using namespace std;

long long n,a[1069][5];

bool chk(long long x,long long y,long long y2)
{
	long long i,j,k,z[3];
	
	for(i=0;i<3;i++)
	{
		z[i]=0;
		for(j=0;j<5;j++)
		{
			k=a[x][j]-a[y][j];
			z[i]+=k*k;
		}
		swap(y,y2);
		swap(x,y);
	}
	return z[0]+z[1]<=z[2];
}

int main()
{
	long long i,j,p[3],z=-1;
	
	scanf("%lld",&n);
	if(n<3)
	{
		printf("%lld\n",n);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",i," \n"[i==n]);
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	p[0]=1;
	for(p[1]=p[0]+1;p[1]<=n;p[1]++)
	{
		for(p[2]=p[1]+1;p[2]<=n;p[2]++)
		{
			for(i=0;i<3;i++)
			{
				if(chk(p[i],p[(i+1)%3],p[(i+2)%3]))
				{
					z=p[i];
				}
			}
		}
	}
	for(i=1;i<=n&&z!=-1;i++)
	{
		for(j=i+1;j<=n&&z!=-1;j++)
		{
			if(i!=z&&j!=z&&!chk(z,i,j))
			{
				z=-1;
			}
		}
	}
	if(z!=-1)
	{
		printf("1\n%lld\n",z);
	}
	else
	{
		printf("0\n");
	}
}