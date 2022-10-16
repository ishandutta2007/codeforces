#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,sm,sm2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		sm=0;
		sm2=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			sm2+=(k-1)/d+1;
		}
		printf("%lld %lld\n",(sm-1)/d+1,sm2);
	}
}