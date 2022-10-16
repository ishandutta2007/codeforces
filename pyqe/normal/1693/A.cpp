#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm;
	bool bad,bad2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		bad=0;
		bad2=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			bad|=!sm;
			bad2|=sm<0||sm&&bad;
		}
		if(!bad2&&!sm)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}