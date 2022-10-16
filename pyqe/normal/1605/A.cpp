#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		sm=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			sm+=k;
		}
		printf("%lld\n",(long long)!!(sm%3));
	}
}