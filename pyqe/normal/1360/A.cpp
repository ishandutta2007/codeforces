#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		z=max(k*2,l);
		printf("%lld\n",z*z);
	}
}