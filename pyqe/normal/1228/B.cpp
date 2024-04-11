#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069],dv=1e9+7;

int main()
{
	long long i,j,ii,k,w,z=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=-1;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			for(j=1;j<=min(k+1,m);j++)
			{
				w=j!=k+1;
				if(ii)
				{
					swap(i,j);
				}
				if(a[i][j]!=-1&&a[i][j]!=w)
				{
					printf("0\n");
					return 0;
				}
				a[i][j]=w;
				if(ii)
				{
					swap(i,j);
				}
			}
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==-1)
			{
				z=z*2%dv;
			}
		}
	}
	printf("%lld\n",z);
}