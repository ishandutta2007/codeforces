#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			bad|=i>1&&k<=l;
			l=k;
		}
		if(n%2==0||bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}