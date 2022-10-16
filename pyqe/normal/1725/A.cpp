#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long z;
	
	scanf("%lld%lld",&n,&m);
	if(m>1)
	{
		z=n*(m-1);
	}
	else
	{
		z=n-1;
	}
	printf("%lld\n",z);
}