#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,ttl=0,a[200069],fq[200069],ps[200069],ps2[200069];
pair<long long,long long> as[200069];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return x.fr*y.sc<y.fr*x.sc;
}

int main()
{
	long long t,rr,i,j,k,l,p,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=max(k,0ll)-a[i];
	}
	fq[1]=1;
	nn=0;
	for(i=1;i<=n;i++)
	{
		for(j=i*2;j<=n;j+=i)
		{
			a[j]-=a[i];
			fq[j]-=fq[i];
		}
		if(fq[i])
		{
			if(fq[i]<0)
			{
				a[i]*=-1;
				fq[i]*=-1;
			}
			nn++;
			as[nn]={-a[i],fq[i]};
		}
		else
		{
			ttl+=abs(a[i]);
		}
	}
	sort(as+1,as+nn+1,cmp);
	for(i=1;i<=n;i++)
	{
		k=as[i].fr;
		l=as[i].sc;
		ps[i]=ps[i-1]+k;
		ps2[i]=ps2[i-1]+l;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		z=ttl;
		p=upper_bound(as+1,as+nn+1,mp(k,1ll))-as-1;
		z+=k*ps2[p]-ps[p];
		z+=ps[nn]-ps[p]-k*(ps2[nn]-ps2[p]);
		printf("%lld\n",z);
	}
}