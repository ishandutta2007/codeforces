#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069],zs=0;
bitset<100069> vtd;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!vtd[k])
		{
			zs++;
			sq[zs]=i;
			vtd[k]=1;
		}
	}
	if(zs<d)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=d;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==d]);
		}
	}
}