#include <bits/stdc++.h>

using namespace std;

long long n,a[250069];

int main()
{
	long long t,rr,i,ii,mn,mx,e,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			mn=a[1];
			mx=a[1];
			e=-1;
			for(i=2;i<=n;i++)
			{
				if(a[i]<mn)
				{
					z+=!!e;
					e=0;
					mn=a[i];
				}
				else if(a[i]>mx)
				{
					z+=e!=1;
					e=1;
					mx=a[i];
				}
			}
			for(i=1;i<n+1-i;i++)
			{
				swap(a[i],a[n+1-i]);
			}
		}
		z=max(z-1,0ll);
		printf("%lld\n",z);
	}
}