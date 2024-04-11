#include <bits/stdc++.h>

using namespace std;

long long n,d,sp[17][100069],lg2[100069],inf=1e18;

void spbd()
{
	long long i,j;
	
	for(i=1;1ll<<i<=n;i++)
	{
		for(j=1;j<=n-(1ll<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
}

long long spqr(long long lh,long long rh)
{
	if(lh>rh)
	{
		return inf;
	}
	long long e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]);
}

struct segtree
{
	long long l,r,mn,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii,k;
		
		l=lh;
		r=rh;
		k=(r-1)/n-(l-1)/n;
		if(!k)
		{
			mn=spqr((l-1)%n+1,(r-1)%n+1);
		}
		else if(k==1)
		{
			mn=min(spqr((l-1)%n+1,n),spqr(1,(r-1)%n+1));
		}
		else
		{
			mn=spqr(1,n);
		}
		lz=-inf;
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
	}
	void blc()
	{
		long long ii,md=(l+r)/2;
		
		for(ii=0;ii<2;ii++)
		{
			if(!p[ii])
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			if(lz!=-inf)
			{
				p[ii]->mn=lz;
				p[ii]->lz=lz;
			}
		}
		lz=-inf;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn=w;
			lz=w;
		}
		else
		{
			long long ii;
			
			blc();
			mn=inf;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mn=min(mn,p[ii]->mn);
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return inf;
		}
		else if(l>=lh&&r<=rh)
		{
			return mn;
		}
		else
		{
			blc();
			return min(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k,l,w;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sp[0][i]);
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	spbd();
	sg.bd(1,n*d);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			scanf("%lld",&w);
			sg.ud(k,l,w);
		}
		else
		{
			printf("%lld\n",sg.qr(k,l));
		}
	}
}