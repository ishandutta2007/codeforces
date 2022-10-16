#include <bits/stdc++.h>

using namespace std;

long long n,ft,m,d;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&ft,&m,&d);
		n=max(n-ft,0ll);
		d=max(m-d,0ll);
		if(!n)
		{
			z=ft;
		}
		else if(d)
		{
			z=((n-1)/d+1)*m+ft;
		}
		else
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}