#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl,a[200069],sq[200069],zs;

int main()
{
	long long t,rr,i,j,k,mx,e;
	pair<long long,long long> mxe;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		mxe={-1,-1};
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
			mxe=max(mxe,{a[i],i});
		}
		mx=mxe.fr;
		e=mxe.sc;
		k=max(mx-(ttl-mx),0ll);
		a[e]-=k;
		ttl-=k;
		a[e]-=ttl%2;
		ttl-=ttl%2;
		zs=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<a[i];j++)
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("%lld\n",zs/2);
		for(i=1;i<=zs/2;i++)
		{
			printf("%lld %lld\n",sq[i],sq[i+zs/2]);
		}
	}
}