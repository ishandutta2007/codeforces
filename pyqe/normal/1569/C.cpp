#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[200069];

int main()
{
	long long t,rr,i,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		if(a[n]-a[n-1]>=2)
		{
			z=0;
		}
		else
		{
			z=1;
			c=0;
			for(i=1;i<=n;i++)
			{
				c+=a[i]==a[n-1];
			}
			for(i=1;i<=n;i++)
			{
				if(a[n-1]==a[n]||i!=c+1)
				{
					z=z*i%dv;
				}
				else
				{
					z=z*(i-1)%dv;
				}
			}
		}
		printf("%lld\n",z);
	}
}