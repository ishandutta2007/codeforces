#include <bits/stdc++.h>

using namespace std;

long long n,zs;
bitset<2069> sq;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%2)
		{
			printf("-1\n");
			continue;
		}
		zs=0;
		for(i=0;i<60;i++)
		{
			if(n>>i&1)
			{
				for(j=0;j<i;j++)
				{
					zs++;
					sq[zs]=j<2;
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",(long long) sq[i]," \n"[i==zs]);
		}
	}
}