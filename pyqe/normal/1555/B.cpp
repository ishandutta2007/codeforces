#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,d,d2;

int main()
{
	long long t,rr,x,y,x2,y2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&x2,&y2,&d,&d2);
		z=inf;
		if(x2-x+d<=n)
		{
			z=min(z,max(min(d-x,x2-(n-d)),0ll));
		}
		if(y2-y+d2<=m)
		{
			z=min(z,max(min(d2-y,y2-(m-d2)),0ll));
		}
		if(z!=inf)
		{
			printf("%lld.000000000\n",z);
		}
		else
		{
			printf("-1\n");
		}
	}
}