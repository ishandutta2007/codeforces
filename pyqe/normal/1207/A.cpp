#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,c,d,e,i,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
		a/=2;
		mx=0;
		for(i=0;i<=a;i++)
		{
			z=min(i,b)*d+min(a-i,c)*e;
			mx=max(mx,z);
		}
		printf("%lld\n",mx);
	}
}