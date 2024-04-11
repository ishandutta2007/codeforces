#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,mx,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		mx=-1e18;
		sm=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			mx=max(mx,k);
			sm+=k;
		}
		scanf("%lld",&n);
		sm+=n;
		if(sm%3==0&&sm/3>=mx)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}