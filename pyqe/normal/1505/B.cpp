#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long sm;
	
	scanf("%lld",&n);
	for(;n>=10;)
	{
		sm=0;
		for(;n;n/=10)
		{
			sm+=n%10;
		}
		n=sm;
	}
	printf("%lld\n",n);
}