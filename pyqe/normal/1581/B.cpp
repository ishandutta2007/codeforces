#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		if(m<n-1||m>n*(n-1)/2)
		{
			z=0;
		}
		else if(d>3)
		{
			z=1;
		}
		else if(d==3&&m==n*(n-1)/2)
		{
			z=1;
		}
		else if(d==2&&n==1)
		{
			z=1;
		}
		else
		{
			z=0;
		}
		if(z)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}