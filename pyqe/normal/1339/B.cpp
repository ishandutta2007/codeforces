#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069];

int main()
{
	long long t,rr,i,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(p=2,i=n/2;i;i--,p+=2)
		{
			sq[p]=a[i];
		}
		for(p=1,i=n/2+1;i<=n;i++,p+=2)
		{
			sq[p]=a[i];
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}