#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long t,rr,k,gd,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		gd=__gcd(m-1,d);
		k=d/gd;
		n=min(n,m);
		z=tri(n/k+1)*(n%k)+tri(n/k)*(k-n%k);
		printf("%lld\n",z);
	}
}