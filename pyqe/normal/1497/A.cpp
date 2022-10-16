#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069],zs;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(i==1||a[i]!=a[i-1])
			{
				zs++;
				sq[zs]=a[i];
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i>1&&a[i]==a[i-1])
			{
				zs++;
				sq[zs]=a[i];
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}