#include <bits/stdc++.h>

using namespace std;

long long n,a[5069],dsu[5069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n+1;i++)
		{
			dsu[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(a[i]==1)
			{
				dsu[i]=fd(i+1);
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=max(a[i]-n,0ll);
			a[i]=min(a[i],n);
			if(a[i]==1)
			{
				dsu[i]=fd(i+1);
			}
			for(;a[i]-1;z++)
			{
				for(p=i;p<=n&&fd(p)<=n;p+=a[p]+1)
				{
					p=fd(p);
					a[p]--;
					if(a[p]==1)
					{
						dsu[p]=fd(p+1);
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}