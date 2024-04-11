#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> vtd;

int main()
{
	long long t,rr,i,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		vtd.reset();
		sm=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			vtd[k%2]=1;
			sm+=k;
		}
		if(sm%2||(vtd[0]&&vtd[1]))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}