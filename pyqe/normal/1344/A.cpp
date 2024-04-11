#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e9;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,k,tg,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			vtd[i]=0;
		}
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			tg=(i+k+n*inf)%n;
			c+=!vtd[tg];
			vtd[tg]=1;
		}
		if(c==n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}