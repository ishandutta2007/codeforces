#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069];

int main()
{
	long long t,rr,i,k,w,p,rm,tg;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
	}
	p=1;
	rm=a[1];
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		w=min(k,rm);
		k-=w;
		rm-=w;
		if(!rm)
		{
			tg=upper_bound(ps+1,ps+n+1,ps[p]+k)-ps-1;
			k-=ps[tg]-ps[p];
			if(tg<n)
			{
				p=tg+1;
				rm=a[p];
				w=min(k,rm);
				rm-=w;
			}
			else
			{
				p=1;
				rm=a[1];
			}
		}
		printf("%lld\n",n+1-p);
	}
}