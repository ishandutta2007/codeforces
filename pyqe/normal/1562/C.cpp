#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<20069> a;

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		for(i=1;i<=n;i++)
		{
			if(!a[i])
			{
				break;
			}
		}
		if(i>n)
		{
			printf("%lld %lld %lld %lld\n",1ll,n/2,2ll,n/2+1);
		}
		else if(i+n/2<=n)
		{
			printf("%lld %lld %lld %lld\n",i,i+n/2,i+1,i+n/2);
		}
		else
		{
			printf("%lld %lld %lld %lld\n",i-n/2,i,i-n/2,i-1);
		}
	}
}