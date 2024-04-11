#include <bits/stdc++.h>

using namespace std;

long long n,m,a[2][1069][1069];

int main()
{
	long long i,j,ii;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&a[ii][i][j]);
				if(ii&&a[1][i][j]<a[0][i][j])
				{
					swap(a[0][i][j],a[1][i][j]);
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if((i-1&&a[ii][i][j]<=a[ii][i-1][j])||(j-1&&a[ii][i][j]<=a[ii][i][j-1]))
				{
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}
	printf("Possible\n");
}