#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		m=abs(n-m);
		if(!m)
		{
			printf("0 0\n");
		}
		else
		{
			printf("%lld %lld\n",m,min(n-n/m*m,(n+m-1)/m*m-n));
		}
	}
}