#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		l=1;
		z=0;
		for(i=n;i;i--)
		{
			if(a[i]!=a[n]&&n+1-i>l)
			{
				z++;
				l=(n-i)*2;
			}
		}
		printf("%lld\n",z);
	}
}