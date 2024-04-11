#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long z;
	
	scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		z=1;
	}
	else if(m-1>=n-m)
	{
		z=m-1;
	}
	else
	{
		z=m+1;
	}
	printf("%lld\n",z);
}