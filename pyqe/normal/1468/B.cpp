#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,ma=1e9,a[200069],ps[200069],sk[200069],qq[200069],dsu[200069],cc[200069],sq[200069];
pair<long long,long long> as[200069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2>=x2*y;
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(ps[x-1]-ps[y2-1],x-y2,ps[x-1]-ps[y-1],x-y);
}

long long f(long long x,long long w)
{
	return x*w-ps[x-1];
}

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,u,k,lh,rh,md,zz,lh2,rh2,md2,zz2;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
		for(;nn>=2&&chk(i,sk[nn],sk[nn-1]);nn--);
		nn++;
		sk[nn]=i;
		for(lh=1,rh=ma;lh<=rh;)
		{
			md=(lh+rh)/2;
			for(zz2=1,lh2=2,rh2=nn;lh2<=rh2;)
			{
				md2=(lh2+rh2)/2;
				if(f(sk[md2],md)>=f(sk[md2-1],md))
				{
					zz2=md2;
					lh2=md2+1;
				}
				else
				{
					rh2=md2-1;
				}
			}
			if(f(sk[zz2],md)-(i+1)*md+ps[i]<=0)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		as[i]={zz,i};
	}
	sort(as+1,as+n,greater<pair<long long,long long>>());
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",qq+rr);
	}
	for(i=1,rr=t;rr;rr--)
	{
		sq[rr]=sq[rr+1];
		for(;i<n&&as[i].fr>qq[rr];i++)
		{
			k=as[i].sc;
			dsu[k]=k;
			cc[k]=1;
			for(u=-1;u<=1;u+=2)
			{
				if(dsu[k+u])
				{
					cc[k]+=cc[fd(k+u)];
					dsu[fd(k+u)]=k;
				}
			}
			sq[rr]=max(sq[rr],cc[k]);
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld%c",sq[rr]," \n"[rr==t]);
	}
}