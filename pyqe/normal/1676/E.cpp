#include <bits/stdc++.h>

using namespace std;

long long n,a[150069],ps[150069];

int main()
{
	long long tt,rrr,t,rr,i,k,p;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+a[i];
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld",&k);
			p=lower_bound(ps+1,ps+n+1,k)-ps;
			if(p>n)
			{
				p=-1;
			}
			printf("%lld\n",p);
		}
	}
}