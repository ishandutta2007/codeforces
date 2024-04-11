#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,y,x,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&m,&y,&x,&d);
		if((y-1<=d||m-x<=d)&&(x-1<=d||n-y<=d))
		{
			z=-1;
		}
		else
		{
			z=n+m-2;
		}
		printf("%lld\n",z);
	}
}