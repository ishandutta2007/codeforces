#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,m;

int main()
{
	long long t,rr,ml,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		ml=1;
		z=0;
		for(;m;m>>=1)
		{
			z=(z+m%2*ml)%dv;
			ml=ml*n%dv;
		}
		printf("%lld\n",z);
	}
}