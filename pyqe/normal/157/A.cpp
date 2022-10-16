#include <bits/stdc++.h>

using namespace std;

long long n,a[2][1069];

int main()
{
	long long i,j,ii,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			for(ii=0;ii<2;ii++)
			{
				a[ii][i]+=k;
				swap(i,j);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+n+1);
	}
	for(j=0,i=1;i<=n;i++)
	{
		for(;j<n&&a[0][j+1]<a[1][i];j++);
		z+=j;
	}
	printf("%lld\n",z);
}