#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,l,p,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=n+1;
		for(i=1;i<=n;i++)
		{
			if(i==1||a[i]!=a[i-1])
			{
				for(c=1,l=i;1;l=p,c++)
				{
					p=lower_bound(a+l+1,a+n+1,a[l]+a[l]-a[i])-a;
					if(p>n)
					{
						break;
					}
				}
				z=min(z,n-c);
			}
		}
		printf("%lld\n",z);
	}
}