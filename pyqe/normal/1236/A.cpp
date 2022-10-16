#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,c,mx,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		mx=0;
		for(i=0;i<=min(a,b/2);i++)
		{
			mx=max(mx,i*3+(min(b-i*2,c/2)*3));
		}
		printf("%lld\n",mx);
	}
}