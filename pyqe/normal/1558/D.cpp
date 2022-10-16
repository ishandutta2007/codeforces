#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=2e5,dv=998244353;
long long n,m,rr,fc[400069],ifc[400069],fw[200069],fi,vi[200069],si[200069],pwk;
pair<long long,long long> a[200069];

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

long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		if(vi[fi]<rr)
		{
			fw[fi]=0;
			vi[fi]=rr;
		}
		fw[fi]+=w;
	}
}

long long bl(long long x)
{
	long long i,sm=0;
	
	fi=0;
	for(i=17;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&vi[fi|1ll<<i]<rr)
		{
			fw[fi|1ll<<i]=0;
			vi[fi|1ll<<i]=rr;
		}
		if((fi|1ll<<i)<=n&&sm+(1ll<<i)-fw[fi|1ll<<i]<x)
		{
			fi|=1ll<<i;
			sm+=(1ll<<i)-fw[fi];
		}
	}
	return fi+1;
}

int main()
{
	long long t,i,k,l,p,c;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=ma*2;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[i]={k,l};
		}
		c=1;
		for(i=m;i;i--)
		{
			k=a[i].fr;
			l=a[i].sc;
			p=bl(l);
			ud(p,1);
			p=bl(l);
			c+=si[p]<rr;
			si[p]=rr;
		}
		printf("%lld\n",cb(n*2-c,n));
	}
}