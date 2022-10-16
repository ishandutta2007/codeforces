#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long dn,n,m,a[200069];
bitset<100069> vtd;

long long av(long long x,long long y)
{
	return (x+y+200000)/2-100000;
}

struct segtree
{
	long long l,r,mx=0,lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r);
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
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
		if(l>rh||r<lh||lh>rh);
		else if(l>=lh&&r<=rh)
		{
			mx+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh||lh>rh)
		{
			return -1e18;
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
sg[2];

int main()
{
	long long i,j,ii,k,kk,p,tg,mx[2],z=0;
	
	scanf("%lld%lld",&dn,&m);
	n=1<<dn;
	for(ii=0;ii<2;ii++)
	{
		sg[ii].bd(-1,n-1);
		sg[ii].ud(0,n-1,-1e17);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
		a[i]--;
		a[i]/=2;
		z+=!vtd[a[i]];
		vtd[a[i]]=1;
		a[i]/=2;
	}
	sort(a+1,a+m+1);
	a[0]=-1;
	for(i=1;i<=m;i++)
	{
		if(a[i-1]==-1)
		{
			k=dn-1;
		}
		else
		{
			for(k=0,kk=a[i]^a[i-1];kk;kk/=2,k++);
		}
		for(ii=0;ii<2;ii++)
		{
			mx[!ii]=-1e17;
			p=-(1<<dn-2);
			for(j=dn-1;j+1;j--)
			{
				tg=p+(1<<max(j-1,0ll))-1;
				if(tg>=a[i]+!j)
				{
					tg=p-1;
				}
				mx[!ii]=max(mx[!ii],sg[ii].qr(p,tg)+j*(!ii+1));
				p=tg+1;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			sg[ii].ud(-1,n-1,k*(ii+1));
			sg[ii].ud(a[i-1],a[i-1],mx[ii]-sg[ii].qr(a[i-1],a[i-1]));
		}
		z+=(i==1);
	}
	z+=max(sg[0].qr(-1,n-1),sg[1].qr(-1,n-1));
	printf("%lld\n",z);
}