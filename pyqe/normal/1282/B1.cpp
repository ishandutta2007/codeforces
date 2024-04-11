#include <bits/stdc++.h>

using namespace std;

long long n,d,dv,a[200069],mo[200069],ps[200069];

int main()
{
	long long t,rr,i,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&dv);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=0;i<dv;i++)
		{
			mo[i]=0;
		}
		mx=0;
		for(i=1;i<=n;i++)
		{
			mo[i%dv]+=a[i];
			ps[i]=ps[i-1]+a[i];
			if(mo[i%dv]+ps[max(i%dv-1,0ll)]<=d)
			{
				mx=i;
			}
		}
		printf("%lld\n",mx);
	}
}