#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		printf("%lld\n",n);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",i," \n"[i==n]);
		}
	}
}