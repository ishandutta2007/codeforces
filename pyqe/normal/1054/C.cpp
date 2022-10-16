#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,j,k,g=true,z;
	
	scanf("%lld",&n);
	long long a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k>i)
		{
			g=false;
		}
		a[i]=k;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(i+k>=n)
		{
			g=false;
		}
		b[i]=k;
		if(a[i]+b[i]>=n)
		{
			g=false;
		}
	}
	if(!g)
	{
		printf("NO\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		c[i]=n-a[i]-b[i];
	}
	for(i=0;i<n;i++)
	{
		z=0;
		for(j=i+1;j<n;j++)
		{
			if(c[j]>c[i])
			{
				z++;
				if(z>b[i])
				{
					break;
				}
			}
		}
		if(z!=b[i])
		{
			printf("NO\n");
			return 0;
		}
		z=0;
		for(j=i-1;j>=0;j--)
		{
			if(c[j]>c[i])
			{
				z++;
				if(z>a[i])
				{
					break;
				}
			}
		}
		if(z!=a[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%lld",c[i]);
	}
	printf("\n");
}