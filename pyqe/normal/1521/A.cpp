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
		if(m==1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n%lld %lld %lld\n",n,n*(m*2-1),n*m*2);
	}
}