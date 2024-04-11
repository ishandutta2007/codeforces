#include <bits/stdc++.h>

using namespace std;

long long n,m,ls[1069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			ls[k]=rr;
		}
		z=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			if(ls[k]==rr)
			{
				z=k;
			}
		}
		if(!z)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n1 %lld\n",z);
		}
	}
}