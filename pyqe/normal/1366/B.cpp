#include <bits/stdc++.h>

using namespace std;

long long n,m,lb,rb;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&lb,&m);
		rb=lb;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			if(k<=rb&&l>=lb)
			{
				lb=min(lb,k);
				rb=max(rb,l);
			}
		}
		printf("%lld\n",rb-lb+1);
	}
}