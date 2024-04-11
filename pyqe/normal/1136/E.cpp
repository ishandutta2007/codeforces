#include <bits/stdc++.h>

using namespace std;

long long n,fw[2][100069],fi,ps[100069];

void ud(long long ky,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[ky][fi]+=w;
	}
}

long long qr(long long ky,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[ky][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[ky][fi];
	}
	return z;
}

long long bl(long long ky,long long x)
{
	long long i,sm=0;
	
	for(fi=0,i=16;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&sm+fw[ky][fi|1ll<<i]<=x)
		{
			fi|=1ll<<i;
			sm+=fw[ky][fi];
		}
	}
	return fi;
}

void ud2(long long x,long long w)
{
	ud(0,x,w);
	ud(1,x,w*(n+1-x));
}

int main()
{
	long long t,rr,i,k,l=0,w,p,sm,z;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ud2(i,k-l);
		l=k;
	}
	sm=0;
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		ud2(i,-k);
		sm+=k;
		ps[i]=ps[i-1]+sm;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld%lld",&ch,&k,&l);
		if(ch=='+')
		{
			ud2(k,l);
			k=qr(0,1,k);
			for(;l;)
			{
				p=bl(0,k);
				if(p==n)
				{
					break;
				}
				w=min(qr(0,1,p+1)-k,l);
				ud2(p+1,-w);
				l-=w;
			}
		}
		else
		{
			z=qr(0,1,k-1)*(l-k+1)+qr(1,k,l)-qr(0,k,l)*(n-l)+ps[l]-ps[k-1];
			printf("%lld\n",z);
		}
	}
}