#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",a+i);
			}
			sort(a+1,a+n+1);
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",a[i]," \n"[i==n]);
			}
		}
	}
}