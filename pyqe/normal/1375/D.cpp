#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],sq[2069],zs;
bitset<1069> vtd;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		zs=0;
		for(;1;)
		{
			for(i=0;i<=n;i++)
			{
				vtd[i]=0;
			}
			for(i=1;i<=n;i++)
			{
				vtd[a[i]]=1;
			}
			for(i=0;vtd[i];i++);
			if(i<n)
			{
				a[i+1]=i;
				zs++;
				sq[zs]=i+1;
			}
			else
			{
				for(i=1;i<=n;i++)
				{
					if(a[i]!=i-1)
					{
						a[i]=n;
						zs++;
						sq[zs]=i;
						i=-1;
						break;
					}
				}
				if(i!=-1)
				{
					break;
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}