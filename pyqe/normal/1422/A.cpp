#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		printf("%lld\n",k+l+w-1);
	}
}