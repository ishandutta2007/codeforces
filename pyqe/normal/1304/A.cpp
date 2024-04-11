#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
		if((m-n)%(k+l)!=0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",(m-n)/(k+l));
		}
	}
}