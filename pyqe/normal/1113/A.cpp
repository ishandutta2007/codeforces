#include <bits/stdc++.h>

using namespace std;

long long n,d;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long k;
	
	scanf("%lld%lld",&n,&d);
	k=min(n-1,d);
	printf("%lld\n",k+tri(n-k)-1);
}