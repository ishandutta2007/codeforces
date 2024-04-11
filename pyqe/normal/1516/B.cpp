#include <bits/stdc++.h>

using namespace std;

long long n,ps[2069];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ps[i]=ps[i-1]^k;
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if((!i||ps[i]==(ps[j]^ps[i]))&&(ps[j]^ps[i])==(ps[n]^ps[j]))
				{
					break;
				}
			}
			if(j<n)
			{
				break;
			}
		}
		if(i<n-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}