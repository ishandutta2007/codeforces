#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<d*2;i+=2)
	{
		z+=(n-i*2)*(m-i*2)-max(n-i*2-2,0ll)*max(m-i*2-2,0ll);
	}
	printf("%lld\n",z);
}