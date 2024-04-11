#include <bits/stdc++.h>

using namespace std;

long long n,d,ps[11];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=10;i++)
		{
			ps[i]=ps[i-1]+d*i%10;
		}
		printf("%lld\n",n/d/10*ps[10]+ps[n/d%10]);
	}
}