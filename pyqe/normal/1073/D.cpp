#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],fw[2][200069],fi;

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

long long bl(long long xx,long long x)
{
	long long i;
	
	fi=0;
	for(i=17;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&fw[xx][fi|1ll<<i]<=x)
		{
			fi|=1ll<<i;
			x-=fw[xx][fi];
		}
	}
	return fi+1;
}

int main()
{
	long long i,p=0,tg,c,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ud(0,i,a[i]);
		ud(1,i,1);
	}
	for(c=0;c<n;)
	{
		if(!p)
		{
			z+=d/qr(0,1,n)*(n-c);
			d%=qr(0,1,n);
		}
		tg=bl(0,d+qr(0,1,p));
		z+=qr(1,p+1,tg-1);
		d-=qr(0,p+1,tg-1);
		if(tg<=n)
		{
			c++;
			ud(0,tg,-a[tg]);
			ud(1,tg,-1);
			p=tg;
		}
		else
		{
			p=0;
		}
	}
	printf("%lld\n",z);
}