#include <bits/stdc++.h>

using namespace std;

long long n,lb,rb;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&lb,&rb,&n);
		for(i=lb;i<=rb;i++)
		{
			k=n/i*i;
			if(k&&k+rb-lb>=n)
			{
				printf("%lld %lld %lld\n",i,rb,k+rb-n);
				break;
			}
			k+=i;
			if(k+lb-rb<=n)
			{
				printf("%lld %lld %lld\n",i,lb,k+lb-n);
				break;
			}
		}
		
	}
}