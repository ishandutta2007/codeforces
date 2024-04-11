#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2],wg[2];

int main()
{
	long long t,rr,i,k,l,w,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld",n,n+1,a,a+1,wg,wg+1);
		if(wg[0]>wg[1])
		{
			swap(a[0],a[1]);
			swap(wg[0],wg[1]);
		}
		z=0;
		for(i=0;i<=min(a[0],n[0]/wg[0]);i++)
		{
			w=min((n[0]-i*wg[0])/wg[1],a[1]);
			sm=i+w;
			k=a[0]-i;
			l=a[1]-w;
			w=min(n[1]/wg[0],k);
			sm+=w;
			k=n[1]-w*wg[0];
			sm+=min(k/wg[1],l);
			z=max(z,sm);
		}
		printf("%lld\n",z);
	}
}