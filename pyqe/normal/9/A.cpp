#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,mx,n,gd;
	
	scanf("%lld%lld",&a,&b);
	mx=max(a,b);
	n=7-mx;
	gd=__gcd(n,(long long)6);
	printf("%lld/%lld\n",n/gd,6/gd);
}