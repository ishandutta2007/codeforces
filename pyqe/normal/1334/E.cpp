#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,mxn=1e5,fz[100069],fc[100069],ifc[100069],z,c,pwk,dv=998244353,inf=1e18;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long dr(long long x)
{
	long long i,w,ww=1;
	
	for(i=1;i<=nn;i++)
	{
		for(w=0;x%fz[i]==0;x/=fz[i],w++);
		ww*=w+1;
	}
	return ww;
}

long long ct(long long x)
{
	long long i,w,sm=0,ww=1;
	
	for(i=1;i<=nn;i++)
	{
		for(w=0;x%fz[i]==0;x/=fz[i],w++);
		sm+=w;
		ww=ww*ifc[w]%dv;
	}
	ww=ww*fc[sm]%dv;
	return ww;
}

void ud(long long x,long long w)
{
	if(x<z)
	{
		z=x;
		c=0;
	}
	if(x==z)
	{
		c=(c+w)%dv;
	}
}

int main()
{
	long long t,rr,i,k,l,gd,lm,w,sm;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=mxn;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	scanf("%lld",&n);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			nn++;
			fz[nn]=i;
			for(;n%i==0;n/=i);
		}
	}
	if(n>1)
	{
		nn++;
		fz[nn]=n;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		gd=__gcd(k,l);
		lm=k/gd*l;
		z=inf;
		w=dr(k)+dr(l)-dr(gd)*2;
		sm=ct(k/gd)*ct(l/gd)%dv;
		ud(w,sm);
		if(gd<min(k,l))
		{
			w=dr(lm)*2-dr(k)-dr(l);
			sm=ct(k/gd)*ct(l/gd)%dv;
			ud(w,sm);
		}
		printf("%lld\n",c);
	}
}