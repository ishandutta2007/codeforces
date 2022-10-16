#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,ft,ls;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(!i)
			{
				ft=k;
			}
			ls=k;
		}
		if(ft<=ls)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}