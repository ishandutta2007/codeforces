#include <bits/stdc++.h>

using namespace std;

long long n,fc=1,z=0,dv=998244353;

int main()
{
	long long i,k=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		fc=fc*i%dv;
	}
	z+=fc;
	for(i=n;i>0;i--)
	{
		k=k*i%dv;
		z=(z+fc-k+dv)%dv;
	}
	printf("%lld\n",z);
}