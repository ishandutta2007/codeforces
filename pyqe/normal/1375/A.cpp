#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,u,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		u=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			printf("%lld%c",abs(k)*u," \n"[i==n]);
			u*=-1;
		}
	}
}