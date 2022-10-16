#include <bits/stdc++.h>

using namespace std;

long long n;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,k,l,z=0;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z+=k*n+max(l*tri(n-1),l*(tri((n-1)/2)+tri(n/2)));
	}
	printf("%.20lf\n",(double)z/n);
}