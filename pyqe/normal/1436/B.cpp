#include <bits/stdc++.h>

using namespace std;

long long n;

bool ip(long long x)
{
	long long i;
	
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	long long t,rr,i,j,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=n;1;i++)
		{
			if(ip(i)&&!ip(i-(n-1)))
			{
				z=i;
				break;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					k=z-(n-1);
				}
				else
				{
					k=1;
				}
				printf("%lld%c",k," \n"[j==n]);
			}
		}
	}
}