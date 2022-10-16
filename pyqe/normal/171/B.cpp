#include <bits/stdc++.h>

using namespace std;

long long n;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long z;
	
	scanf("%lld",&n);
	z=tri(n*3-2)+tri(n-1)*3;
	printf("%lld\n",z);
}