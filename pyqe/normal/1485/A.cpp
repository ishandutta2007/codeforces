#include <bits/stdc++.h>

using namespace std;

long long n,m,inf=1e18;

int main()
{
	long long t,rr,i,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=inf;
		for(i=m==1;i<=z;i++)
		{
			for(c=0,k=n;k;k/=(m+i),c++);
			z=min(z,i+c);
		}
		printf("%lld\n",z);
	}
}