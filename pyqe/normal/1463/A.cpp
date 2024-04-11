#include <bits/stdc++.h>

using namespace std;

long long inf=1e18;

int main()
{
	long long t,rr,i,k,sm,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		sm=0;
		mn=inf;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			mn=min(mn,k);
		}
		if(sm%9==0&&sm/9<=mn)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}