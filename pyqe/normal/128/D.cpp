#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[100069],inf=1e18;

int main()
{
	long long i,mn=inf,mx=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if(mx-mn+1>n)
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		fq[a[i]-mn]++;
	}
	for(i=0;i<=mx-mn;i++)
	{
		fq[i]-=1+(i&&i<mx-mn);
		if(fq[i]<0)
		{
			printf("NO\n");
			return 0;
		}
	}
	for(i=1;i<=mx-mn+1;i++)
	{
		if(fq[i]<fq[i-1])
		{
			printf("NO\n");
			return 0;
		}
		fq[i]-=fq[i-1];
	}
	printf("YES\n");
}