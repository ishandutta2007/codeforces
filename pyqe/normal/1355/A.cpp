#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(mn=inf,i=0;i<d-1&&mn;d--)
		{
			mn=inf;
			mx=-inf;
			for(k=n;k;k/=10)
			{
				mn=min(mn,k%10);
				mx=max(mx,k%10);
			}
			n+=mn*mx;
		}
		printf("%lld\n",n);
	}
}