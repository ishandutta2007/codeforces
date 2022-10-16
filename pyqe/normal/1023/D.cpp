#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,aa[200069],a[200069],fw[200069],fwp;
pair<long long,long long> as[200069];

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fwp=rh;fwp;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	for(fwp=lh-1;fwp;fwp-=fwp&-fwp)
	{
		z-=fw[fwp];
	}
	return z;
}

int main()
{
	long long i,ii,u,k,ls;
	bool bad=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
		bad&=aa[i]!=m;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			if(aa[i])
			{
				a[i]=aa[i];
			}
			else if(!a[i])
			{
				a[i]=a[i-u];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!a[i]||(bad&&!aa[i]))
		{
			a[i]=m;
			bad=0;
		}
		as[i]={a[i],i};
	}
	if(bad)
	{
		printf("NO\n");
		return 0;
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		k=as[i].sc;
		if(i==1||as[i].fr<as[i-1].fr)
		{
			ls=k;
		}
		ud(k,1);
		if(qr(k,ls)<ls-k+1)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}