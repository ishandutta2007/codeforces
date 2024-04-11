#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sm[100069];

int main()
{
	long long i,j,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=3;i<=n;i++)
	{
		if(n%i==0)
		{
			for(j=0;j<n/i;j++)
			{
				sm[j]=0;
			}
			for(j=1;j<=n;j++)
			{
				sm[j%(n/i)]+=a[j];
			}
			for(j=0;j<n/i;j++)
			{
				mx=max(mx,sm[j]);
			}
		}
	}
	printf("%lld\n",mx);
}