#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr;
	bool z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		if(m==1)
		{
			z=0;
		}
		else if(n==m)
		{
			z=1;
		}
		else if(d>=(m+1)/2-n/2)
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