#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
bitset<200069> z;

int main()
{
	long long i,mx=-1e18,mn=1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>mx&&a[i]<mn)
		{
			if(i==n||a[i]<a[i+1])
			{
				z[i]=0;
				mx=a[i];
			}
			else
			{
				z[i]=1;
				mn=a[i];
			}
		}
		else if(a[i]>mx)
		{
			z[i]=0;
			mx=a[i];
		}
		else if(a[i]<mn)
		{
			z[i]=1;
			mn=a[i];
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%d%c",(bool)z[i]," \n"[i==n]);
	}
}