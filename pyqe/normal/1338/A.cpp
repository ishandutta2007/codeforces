#include <bits/stdc++.h>
 
using namespace std;
 
long long n,inf=1e18;
 
int main()
{
	long long t,rr,i,k,mx,z,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=-inf;
		z=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z=max(z,mx-k);
			mx=max(mx,k);
		}
		for(c=0;z>0;z/=2,c++);
		printf("%lld\n",c);
	}
}