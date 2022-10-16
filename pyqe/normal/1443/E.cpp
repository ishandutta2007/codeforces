#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],wg[200069],fw[200069],fi;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long bl(long long x)
{
	long long i;
	
	fi=0;
	for(i=17;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&fw[fi|1ll<<i]<=x)
		{
			fi|=1ll<<i;
			x-=fw[fi];
		}
	}
	return fi+1;
}

int main()
{
	long long t,rr,i,ky,k,l;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		ps[i]=ps[i-1]+a[i];
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			printf("%lld\n",ps[l]-ps[k-1]);
		}
		else
		{
			for(i=n;k;i--)
			{
				wg[i]+=k;
				k=wg[i]/(n+1-i);
				wg[i]%=(n+1-i);
				ud(a[i],1);
			}
			for(i++;i<=n;i++)
			{
				a[i]=bl(wg[i]);
				ps[i]=ps[i-1]+a[i];
				ud(a[i],-1);
			}
		}
	}
}