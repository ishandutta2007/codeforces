#include <bits/stdc++.h>

using namespace std;

long long n,m,ttl,a[1069][1069],inf=1e18;

int main()
{
	long long t,rr,i,k,mn;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		ttl=0;
		bad=0;
		mn=inf;
		for(i=0;i<n*m;i++)
		{
			scanf("%lld",&k);
			ttl+=abs(k);
			bad^=k<0;
			mn=min(mn,abs(k));
		}
		printf("%lld\n",ttl-mn*2*bad);
	}
}