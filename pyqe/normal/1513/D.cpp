#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sp[18][200069],lg2[200069],dsu[200069];
pair<long long,long long> as[200069];

void spbd()
{
	long long i,j,k;
	
	for(i=1;1ll<<i<=n;i++)
	{
		for(j=1;j<=n-(1ll<<i)+1;j++)
		{
			sp[i][j]=__gcd(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(lg2[i]=0,k=i;k>1;k/=2,lg2[i]++);
	}
}

long long qr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	
	return __gcd(sp[e][lh],sp[e][rh-(1ll<<e)+1]);
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
	long long t,rr,i,k,w,lh,rh,md,lb,rb,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
			sp[0][i]=k;
			dsu[i]=i;
		}
		sort(as+1,as+n+1);
		spbd();
		z=0;
		for(i=1;i<=n;i++)
		{
			w=as[i].fr;
			k=as[i].sc;
			for(lh=1,rh=k;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(qr(md,k)==w)
				{
					lb=md;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			for(lh=k,rh=n;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(qr(k,md)==w)
				{
					rb=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			for(;fd(lb)<rb;dsu[fd(lb)]=fd(fd(lb)+1))
			{
				z+=min(w,d);
			}
		}
		for(;fd(1)<n;dsu[fd(1)]=fd(fd(1)+1))
		{
			z+=d;
		}
		printf("%lld\n",z);
	}
}