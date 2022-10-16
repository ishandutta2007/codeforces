#include <bits/stdc++.h>

using namespace std;

long long n,ft[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,k;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		bad=1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(!vtd[k])
			{
				ft[k]=i;
				vtd[k]=1;
			}
			bad&=i-ft[k]<=1;
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}