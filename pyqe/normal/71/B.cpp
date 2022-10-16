#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	z=d*n*m/100;
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",max(min(z-m*(i-1),m),0ll)," \n"[i==n]);
	}
}