#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,z;
	
	scanf("%lld%lld",&n,&m);
	z=((n-1)/2/m+1)*m;
	if(z>n)
	{
		z=-1;
	}
	printf("%lld\n",z);
}