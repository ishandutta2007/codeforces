#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		printf("%lld\n",d/2+n-d);
		for(i=(d+1)/2;i<d;i++)
		{
			printf("%lld%c",i," \n"[i==n-1]);
		}
		for(i=d+1;i<=n;i++)
		{
			printf("%lld%c",i," \n"[i==n]);
		}
	}
}