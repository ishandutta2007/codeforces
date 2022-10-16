#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,a[400069];
pair<long long,long long> ca[400069];

int main()
{
	long long t,rr,i,j,k,l,sz,gd,e,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		gd=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			gd=__gcd(gd,a[i]);
		}
		for(i=n+1;i<=n*2;i++)
		{
			a[i]=a[i-n];
		}
		n*=2;
		for(i=1;i<=n;i++)
		{
			a[i]/=gd;
		}
		nn=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			nn++;
			ca[nn]={i,a[i]};
			sz=nn;
			nn=0;
			for(j=1;j<=sz;j++)
			{
				k=ca[j].fr;
				l=__gcd(ca[j].sc,a[i]);
				if(!nn||l!=ca[nn].sc)
				{
					nn++;
					ca[nn]={k,l};
				}
			}
			e=1+(ca[1].sc==1);
			if(e<=nn)
			{
				z=max(z,i-ca[e].fr+1);
			}
		}
		printf("%lld\n",z);
	}
}