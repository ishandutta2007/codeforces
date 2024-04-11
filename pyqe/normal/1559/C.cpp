#include <bits/stdc++.h>

using namespace std;

long long n,zs;
bitset<10069> a;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]=k;
		}
		a[0]=0;
		a[n+1]=1;
		for(i=1;i<=n+1;i++)
		{
			if(!a[i-1]&&a[i])
			{
				zs=0;
				for(j=1;j<i;j++)
				{
					zs++;
					printf("%lld ",j);
				}
				zs++;
				printf("%lld%c",n+1," \n"[zs==n+1]);
				for(j=i;j<=n;j++)
				{
					zs++;
					printf("%lld%c",j," \n"[zs==n+1]);
				}
				break;
			}
		}
	}
}