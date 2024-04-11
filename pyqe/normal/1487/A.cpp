#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,mn,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn=inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			c=c*(k>=mn)+(k<=mn);
			mn=min(mn,k);
		}
		printf("%lld\n",n-c);
	}
}