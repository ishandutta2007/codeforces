#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		if(k%3==0)
		{
			printf("%lld\n",a);
		}
		else if(k%3==1)
		{
			printf("%lld\n",b);
		}
		else
		{
			printf("%lld\n",a^b);
		}
	}
}