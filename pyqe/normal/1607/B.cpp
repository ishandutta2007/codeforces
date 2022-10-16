#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		if(d%4==0)
		{
			w=0;
		}
		else if(d%4==1)
		{
			w=-d;
		}
		else if(d%4==2)
		{
			w=1;
		}
		else if(d%4==3)
		{
			w=d+1;
		}
		printf("%lld\n",n+w*(!(n%2)*2-1));
	}
}