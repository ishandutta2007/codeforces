#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,k2,l2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&k,&l,&k2,&l2);
		if(!(l<k2||l2<k))
		{
			printf("%lld\n",max(k,k2));
		}
		else
		{
			printf("%lld\n",k+k2);
		}
	}
}