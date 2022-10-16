#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k*2>l)
		{
			printf("-1 -1\n");
		}
		else
		{
			printf("%lld %lld\n",k,k*2);
		}
	}
}