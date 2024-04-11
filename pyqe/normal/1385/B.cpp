#include <bits/stdc++.h>

using namespace std;

long long n,ls[100069];

int main()
{
	long long t,rr,i,k,zs;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld",&k);
			if(ls[k]<rr)
			{
				ls[k]=rr;
				zs++;
				printf("%lld%c",k," \n"[zs==n]);
			}
		}
	}
}