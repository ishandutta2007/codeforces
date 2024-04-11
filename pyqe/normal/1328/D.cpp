#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069];

int main()
{
	long long t,rr,i,ls,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ls=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sq[i]=1+(i-1&&a[i]!=a[i-1]&&sq[i-1]==1);
			if(i-1&&a[i]==a[i-1])
			{
				ls=i;
			}
		}
		for(sq[n]=1;(a[max(n-1,1ll)]!=a[n]&&sq[max(n-1,1ll)]==sq[n])||(a[1]!=a[n]&&sq[1]==sq[n]);sq[n]++);
		if(sq[n]==3&&ls)
		{
			for(i=ls;i<n;i++)
			{
				sq[i]=3-sq[i];
			}
			for(sq[n]=1;(a[max(n-1,1ll)]!=a[n]&&sq[max(n-1,1ll)]==sq[n])||(a[1]!=a[n]&&sq[1]==sq[n]);sq[n]++);
		}
		z=-1e18;
		for(i=1;i<=n;i++)
		{
			z=max(z,sq[i]);
		}
		printf("%lld\n",z);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}