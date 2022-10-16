#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		if(m==1)
		{
			if((n-1)%d==0)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			continue;
		}
		for(k=1;k<=n;k*=m)
		{
			if((n-k)%d==0)
			{
				break;
			}
		}
		if(k<=n)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}