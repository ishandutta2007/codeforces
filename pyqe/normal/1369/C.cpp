#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],wg[200069];

int main()
{
	long long t,rr,i,p,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=d;i++)
		{
			scanf("%lld",wg+i);
		}
		sort(wg+1,wg+d+1);
		z=0;
		for(i=1;i<=d;i++)
		{
			z+=a[n+1-i]*(1+(wg[i]==1));
		}
		p=n-d+1;
		for(i=1;i<=d;i++)
		{
			p-=wg[i]-1;
			z+=a[p]*(wg[i]>1);
		}
		printf("%lld\n",z);
	}
}