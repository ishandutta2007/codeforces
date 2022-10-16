#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long t,rr,i,sm,c,c2,c3;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch=='T';
			sm+=a[i];
		}
		if(sm%2)
		{
			printf("NO\n");
			continue;
		}
		c=0;
		c2=0;
		c3=0;
		for(i=1;i<=n;i++)
		{
			if(a[i])
			{
				if(c*2<sm)
				{
					c++;
				}
				else
				{
					if(c2<=c3)
					{
						break;
					}
					c3++;
				}
			}
			else
			{
				if(c<=c2)
				{
					break;
				}
				c2++;
			}
		}
		if(i>n&&c==c2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}