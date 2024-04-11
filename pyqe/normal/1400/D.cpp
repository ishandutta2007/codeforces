#include <bits/stdc++.h>

using namespace std;

long long n,a[3069],fq[3069];

int main()
{
	long long t,rr,i,j,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			fq[i]=0;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=i+1;j<=n;j++)
			{
				z+=sm*(a[j]==a[i]);
				sm+=fq[a[j]];
			}
			fq[a[i]]++;
		}
		printf("%lld\n",z);
	}
}