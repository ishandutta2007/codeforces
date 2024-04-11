#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&k,&l);
		n--;
		if(l*d>n)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",min((n-l*d)/(k-l),d));
	}
}