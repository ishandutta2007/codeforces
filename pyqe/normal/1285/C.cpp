#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0&&__gcd(i,n/i)==1)
		{
			mx=max(mx,i);
		}
	}
	printf("%lld %lld\n",mx,n/mx);
}