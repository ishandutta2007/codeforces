#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		z=1;
		for(ii=0;ii<2;ii++)
		{
			for(;n%2==0;n/=2,z*=2);
			swap(n,m);
		}
		if(z>=d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}