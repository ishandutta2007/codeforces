#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			if(i%2)
			{
				k=(i+1)/2;
			}
			else
			{
				k=n+1-i/2;
			}
			printf("%lld%c",a[k]," \n"[i==n]);
		}
	}
}