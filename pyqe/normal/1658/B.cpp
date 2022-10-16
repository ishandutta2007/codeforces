#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5,dv=998244353;
long long n,fc[100069];

int main()
{
	long long t,rr,i,z;
	
	fc[0]=1;
	for(i=1;i<=ma;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%2)
		{
			z=0;
		}
		else
		{
			z=fc[n/2]*fc[n/2]%dv;
		}
		printf("%lld\n",z);
	}
}