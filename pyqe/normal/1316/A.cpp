#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		sm=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
		}
		printf("%lld\n",min(sm,m));
	}
}