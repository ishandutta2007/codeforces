#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,n,m,d,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&a,&b,&n,&m,&d);
		k=(a-1)/n+1;
		l=(b-1)/m+1;
		if(k+l>d)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld %lld\n",k,l);
		}
	}
}