#include <bits/stdc++.h>

using namespace std;

long long n,d,zs;

int main()
{
	long long t,rr,i,j,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		d--;
		if(n<=61&&d>=1ll<<n-1)
		{
			printf("-1\n");
			continue;
		}
		l=0;
		for(i=1;i<=n;i++)
		{
			if(i<=n-61||i==n||!(d>>n-1-i&1))
			{
				for(j=i;j>l;j--)
				{
					printf("%lld%c",j," \n"[i==n&&j==l+1]);
				}
				l=i;
			}
		}
	}
}