#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long z;
	
	scanf("%lld",&n);
	if(n%2==0)
	{
		z=(n/2+1)*(n/2+1);
	}
	else
	{
		z=(n/2+1)*(n/2+2)*2;
	}
	printf("%lld\n",z);
}