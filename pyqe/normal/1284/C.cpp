#include <bits/stdc++.h>

using namespace std;

long long n,fc[250069],dv;

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&dv);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=1;i<=n;i++)
	{
		z=(z+(n+1-i)*(n+1-i)%dv*fc[i]%dv*fc[n-i])%dv;
	}
	printf("%lld\n",z);
}