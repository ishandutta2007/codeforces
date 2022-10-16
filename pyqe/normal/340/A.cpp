#include <bits/stdc++.h>

using namespace std;

long long lb,rb;

int main()
{
	long long k,l,lm,z;
	
	scanf("%lld%lld%lld%lld",&k,&l,&lb,&rb);
	lm=k/__gcd(k,l)*l;
	z=rb/lm-(lb-1)/lm;
	printf("%lld\n",z);
}