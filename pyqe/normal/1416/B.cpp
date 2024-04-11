#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[10069],zs;
pair<pair<long long,long long>,long long> sq[30069];

void ad(long long x,long long y,long long w)
{
	zs++;
	sq[zs]={{x,y},w};
}

int main()
{
	long long t,rr,i,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		d=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			d+=a[i];
		}
		if(d%n)
		{
			printf("-1\n");
			continue;
		}
		d/=n;
		zs=0;
		for(i=2;i<=n;i++)
		{
			k=(a[i]+i-1)/i*i;
			ad(1,i,k-a[i]);
			ad(i,1,k/i);
		}
		for(i=2;i<=n;i++)
		{
			ad(1,i,d);
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			k=sq[i].fr.fr;
			l=sq[i].fr.sc;
			w=sq[i].sc;
			printf("%lld %lld %lld\n",k,l,w);
		}
	}
}