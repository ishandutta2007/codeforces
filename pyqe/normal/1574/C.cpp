#include <bits/stdc++.h>

using namespace std;

const long long inf=3e18;
long long n,ttl=0,a[200069];

int main()
{
	long long t,rr,i,ii,k,l,p,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	sort(a+1,a+n+1);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		l=ttl-l;
		p=lower_bound(a+1,a+n+1,k)-a;
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			if(p-ii&&p-ii<=n)
			{
				z=min(z,max(k-a[p-ii],0ll)+max(a[p-ii]-l,0ll));
			}
		}
		printf("%lld\n",z);
	}
}