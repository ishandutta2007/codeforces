#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs;

int main()
{
	long long t,rr,i,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=9;i&&n;i--)
		{
			w=min(i,n);
			zs++;
			sq[zs]=w;
			n-=w;
		}
		if(n)
		{
			printf("-1\n");
			continue;
		}
		for(i=zs;i;i--)
		{
			printf("%lld",sq[i]);
		}
		printf("\n");
	}
}