#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		sm=0;
		mx=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			mx=max(mx,k);
		}
		scanf("%lld",&n);
		if(n>=mx*2-sm-1&&n<=sm-3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}