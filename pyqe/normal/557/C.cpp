#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ma=200,ps[100069],fq[269],inf=1e18;
pair<long long,long long> a[100069];

int main()
{
	long long i,j,k,l,w,ls=0,sm,dd,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].sc);
	}
	sort(a+1,a+n+1);
	for(i=n;i;i--)
	{
		ps[i]=ps[i+1]+a[i].sc;
	}
	z=inf;
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		sm=ps[i+1];
		w=max(ls-(i-ls-1),0ll);
		for(j=1;j<=ma;j++)
		{
			dd=min(fq[j],w);
			sm+=dd*j;
			w-=dd;
		}
		z=min(z,sm);
		if(k<a[i+1].fr)
		{
			for(;ls<i;)
			{
				ls++;
				fq[a[ls].sc]++;
			}
		}
	}
	printf("%lld\n",z);
}