#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],sq[200069];

int main()
{
	long long t,rr,i,k,p,mx=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		sq[i]=-max(mx,(ps[n]-1)/i+1);
		mx=max(mx,(ps[i]-1)/i+1);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		p=lower_bound(sq+1,sq+n+1,-k)-sq;
		if(p>n)
		{
			p=-1;
		}
		printf("%lld\n",p);
	}
}