#include <bits/stdc++.h>

using namespace std;

long long n;
double pi=acos(-1);

int main()
{
	long long t,rr,i;
	double w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n*=2;
		w=1.0/tan(pi/n);
		printf("%.9lf\n",w);
	}
}