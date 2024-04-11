#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];
bitset<1069> vtd;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			vtd[a[i]]=1;
		}
		for(i=1;i<1ll<<10;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(!vtd[a[j]^i])
				{
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				break;
			}
		}
		if(i==1ll<<10)
		{
			i=-1;
		}
		printf("%lld\n",i);
	}
}