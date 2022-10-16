#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][2];

int main()
{
	long long i,ii;
	
	scanf("%lld",&n);
	if(n%2)
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		a[n+1][ii]=a[1][ii];
	}
	for(i=1;i<=n/2;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			if(a[i][ii]-a[i+1][ii]!=a[i+n/2+1][ii]-a[i+n/2][ii])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}