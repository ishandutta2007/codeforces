#include <bits/stdc++.h>

using namespace std;

long long n1,n2,d1,d2;

int main()
{
	long long gd;
	
	scanf("%lld%lld%lld%lld",&n1,&n2,&d1,&d2);
	gd=__gcd(d1,d2);
	d1/=gd;
	d2/=gd;
	printf("%lld\n",min(n1/d1,n2/d2));
}