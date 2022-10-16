#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=m+1;j++)
		{
			a[i][j]=1e18;
			if(i<=n&&j<=m)
			{
				scanf("%lld",&a[i][j]);
			}
		}
	}
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			if(!a[i][j])
			{
				a[i][j]=min(a[i+1][j],a[i][j+1])-1;
			}
			if(a[i][j]>=min(a[i+1][j],a[i][j+1]))
			{
				printf("-1\n");
				return 0;
			}
			z+=a[i][j];
		}
	}
	printf("%lld\n",z);
}