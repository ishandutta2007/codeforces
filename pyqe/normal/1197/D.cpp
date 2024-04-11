#include <bits/stdc++.h>

using namespace std;

long long n,d,m,a[300069],ps[10][300069],mx[10];

int main()
{
	long long i,j,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			ps[j][i]=ps[j][i+1]+a[i];
		}
	}
	for(i=0;i<m;i++)
	{
		mx[i]=-1e18;
		for(j=0;j<=n;j++)
		{
			ps[i][j]+=(j+m-i)/m*d;
		}
	}
	for(i=0;i<=n;i++)
	{
		z=max(z,mx[i%m]-ps[i%m][i]);
		for(j=0;j<m;j++)
		{
			mx[j]=max(mx[j],ps[j][i]);
		}
	}
	printf("%lld\n",max(z,0ll));
}