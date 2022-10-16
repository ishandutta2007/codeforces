#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;
double pi=acos(-1);

int main()
{
	long long t,rr,i;
	double w,agl,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n*=2;
		w=0.5/sin(pi/n);
		z=-inf;
		for(i=0;i<n;i++)
		{
			agl=pi/4+pi*2*i/n;
			z=max(z,max(sin(agl),cos(agl))*w*2);
		}
		printf("%.9lf\n",z);
	}
}