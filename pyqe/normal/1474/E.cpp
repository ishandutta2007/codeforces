#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],zs;

long long sqr(long long x)
{
	return x*x;
}

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=sqr(n-1)+sqr(n/2)*(n%2);
		for(i=(n+1)/2;i<n-1;i++)
		{
			z+=sqr(i)*2;
		}
		printf("%lld\n",z);
		for(i=1;i<=n;i++)
		{
			if(i==1)
			{
				a[i]=(n+1)/2+1;
			}
			else if(i<=(n+1)/2)
			{
				a[i]=i-1;
			}
			else if(i<n)
			{
				a[i]=i+1;
			}
			else
			{
				a[i]=(n+1)/2;
			}
			printf("%lld%c",a[i]," \n"[i==n]);
		}
		printf("%lld\n",n-1);
		for(i=(n+1)/2;i>1;i--)
		{
			printf("%lld %lld\n",i,n);
		}
		for(i=(n+1)/2+1;i<=n;i++)
		{
			printf("%lld 1\n",i);
		}
	}
}