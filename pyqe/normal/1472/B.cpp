#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		bad=1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			bad&=k!=1;
		}
		if(sm%2==0&&(sm/2%2==0||!bad))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}