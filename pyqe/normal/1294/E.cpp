#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[200069];

int main()
{
	long long i,j,k,mn,z=0;
	
	scanf("%lld%lld",&n,&m);
	long long a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
			a[i][j]--;
		}
	}
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			if(a[i][j]%m==j&&a[i][j]<n*m)
			{
				k=(i*m+j+n*m-a[i][j])/m%n;
				fq[k]++;
			}
		}
		mn=1e18;
		for(i=0;i<n;i++)
		{
			mn=min(mn,n-fq[i]+i);
		}
		z+=mn;
	}
	printf("%lld\n",z);
}