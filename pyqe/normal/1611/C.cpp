#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069],zs;

int main()
{
	long long t,rr,i,p,p2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(a[i]==n)
			{
				p=i;
			}
			if(a[i]==1)
			{
				p2=i;
			}
		}
		if(p!=1&&p!=n)
		{
			printf("-1\n");
			continue;
		}
		zs=0;
		for(i=p2-1;i;i--)
		{
			if(a[i]!=n)
			{
				zs++;
				sq[zs]=a[i];
			}
		}
		zs++;
		sq[zs]=n;
		for(i=n;i>p2;i--)
		{
			if(a[i]!=n)
			{
				zs++;
				sq[zs]=a[i];
			}
		}
		if(n!=1)
		{
			zs++;
			sq[zs]=1;
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}