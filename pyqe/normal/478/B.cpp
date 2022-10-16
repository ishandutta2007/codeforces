#include <bits/stdc++.h>

using namespace std;

long long f(long long k)
{
	return k*(k-1)/2;
}

int main()
{
	long long n,m;
	
	scanf("%lld%lld",&n,&m);
	printf("%lld %lld",(n%m)*f(((n-1)/m+1))+(m-(n%m))*f(n/m),f(n-m+1));
}