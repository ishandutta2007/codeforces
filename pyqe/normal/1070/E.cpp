#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,fw[2][200069],fi;
pair<long long,long long> as[200069];

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	return z;
}

long long bl(long long xx,long long x)
{
	long long i,sm=0;
	
	fi=0;
	for(i=17;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&sm+fw[xx][fi|1ll<<i]<x)
		{
			fi|=1ll<<i;
			sm+=fw[xx][fi];
		}
	}
	return fi+!!x;
}

int main()
{
	long long t,rr,i,ii,k,w,lh,rh,md,zz;
	pair<long long,long long> z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
			for(ii=0;ii<2;ii++)
			{
				fw[ii][i]=0;
			}
		}
		sort(as+1,as+n+1);
		z={0,0};
		for(i=1;i<=n;i++)
		{
			w=as[i].fr;
			k=as[i].sc;
			if(w>d)
			{
				break;
			}
			ud(0,k,1);
			ud(1,k,w);
			if(i==n||as[i+1].fr!=w)
			{
				for(zz=0,lh=1,rh=n;lh<=rh;)
				{
					md=(lh+rh)/2;
					if(qr(1,md)+qr(1,bl(0,max(qr(0,md)-1,0ll)/m*m))<=d)
					{
						zz=md;
						lh=md+1;
					}
					else
					{
						rh=md-1;
					}
				}
				z=max(z,{qr(0,zz),w});
			}
		}
		printf("%lld %lld\n",z.fr,max(z.sc,1ll));
	}
}