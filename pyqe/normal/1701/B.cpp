#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,p,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		printf("2\n");
		c=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				for(p=i;p<=n;p*=2)
				{
					vtd[p]=1;
					c++;
					printf("%lld%c",p," \n"[c==n]);
				}
			}
		}
	}
}