#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,l,gd;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		gd=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(i)
			{
				gd=__gcd(gd,abs(k-l));
			}
			l=k;
		}
		if((d%gd+gd)%gd==(k%gd+gd)%gd)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}