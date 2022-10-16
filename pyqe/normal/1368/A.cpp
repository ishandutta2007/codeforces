#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&n);
		if(k<l)
		{
			swap(k,l);
		}
		for(z=0;k<=n;z++)
		{
			swap(k,l);
			k+=l;
		}
		printf("%lld\n",z);
	}
}