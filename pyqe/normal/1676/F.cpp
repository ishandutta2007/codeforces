#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d,a[200069],fq[200069];

int main()
{
	long long t,rr,i,sz,l,fh;
	pair<long long,long long> z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		sz=n;
		n=0;
		for(i=1;i<=sz;i++)
		{
			if(!n||a[i]!=a[n])
			{
				n++;
				a[n]=a[i];
				fq[n]=0;
			}
			fq[n]++;
		}
		z.fr=-inf;
		l=-1;
		for(i=1;i<=n;i++)
		{
			if(fq[i]>=d)
			{
				if(l!=a[i]-1)
				{
					fh=a[i];
				}
				z=max(z,{a[i]-fh+1,a[i]});
				l=a[i];
			}
			else
			{
				l=-1;
			}
		}
		if(z.fr!=-inf)
		{
			printf("%lld %lld\n",z.sc-z.fr+1,z.sc);
		}
		else
		{
			printf("-1\n");
		}
	}
}