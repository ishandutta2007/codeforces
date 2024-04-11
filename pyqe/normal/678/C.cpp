#include <bits/stdc++.h>

using namespace std;

long long n,m1,m2,d1,d2;

int main()
{
	long long i,lm;
	
	scanf("%lld%lld%lld%lld%lld",&n,&m1,&m2,&d1,&d2);
	lm=m1*m2/__gcd(m1,m2);
	printf("%lld\n",n/m1*d1+n/m2*d2-n/lm*min(d1,d2));
}