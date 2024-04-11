#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m;

int main()
{
	long long i,z=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n+m;i++)
	{
		z=z*2%dv;
	}
	printf("%lld\n",z);
}