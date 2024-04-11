#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[400069],lg2[400069],dh[400069],cdh=1,inf=1e18;
pair<long long,long long> sp[19][400069];

struct segtree
{
	long long l,r,mx,lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx=dh[l];
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			mx=-inf;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mx+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			mx=-inf;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -inf;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			blc();
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

long long qr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	pair<long long,long long> tmp=min(sp[e][lh],sp[e][rh-(1ll<<e)+1]);
	
	return tmp.sc;
}

void bd(long long lh,long long rh)
{
	if(lh>rh)
	{
		return;
	}
	long long p=qr(lh,rh);
	
	dh[p]=cdh;
	cdh++;
	bd(lh,p-1);
	bd(p+1,rh);
	cdh--;
}

int main()
{
	long long i,j,k,lh,rh,md,zz;
	pair<long long,long long> z={inf,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n+1;i<=n*2;i++)
	{
		a[i]=a[i-n];
	}
	for(i=0;i<19;i++)
	{
		for(j=1;j<=n*2-(1ll<<i)+1;j++)
		{
			if(!i)
			{
				sp[i][j]={a[j],j};
			}
			else
			{
				sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
			}
		}
	}
	bd(1,n);
	sg.bd(1,n*2);
	for(i=0;i<n;)
	{
		z=min(z,{sg.mx,i});
		for(lh=i+1,rh=i+n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(a[qr(i+1,md)]>=a[i+1])
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		sg.ud(i+1,zz,-1);
		sg.ud(i+1,i+1,-sg.qr(i+1,i+1));
		i++;
		for(lh=i+1,rh=i+n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(a[qr(md,i+n)]>=a[i+n])
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		sg.ud(i+n,i+n,sg.qr(zz-1,zz-1));
		sg.ud(zz,i+n,1);
	}
	printf("%lld %lld\n",z.fr,z.sc);
}