#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,mx=0;
	
	scanf("%lld",&n);
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			mx=i;
		}
	}
	printf("%lld %lld\n",mx,n/mx);
}