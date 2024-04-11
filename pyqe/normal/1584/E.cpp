#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n;

struct val
{
	long long mn[2]={inf,inf},c[2]={0,0};
}
val0;

struct segtree
{
	long long l,r,lz;
	val ans;
	segtree *p[2];
	
	val mrg(val x,val y)
	{
		long long ii,jj;
		val tmp;
		
		for(ii=0;ii<2;ii++)
		{
			tmp.mn[ii]=min(x.mn[ii],y.mn[ii]);
			for(jj=0;jj<2;jj++)
			{
				tmp.c[ii]+=x.c[ii]*(x.mn[ii]==tmp.mn[ii]);
				swap(x,y);
			}
		}
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			ans.mn[l%2]=0;
			ans.c[l%2]=1;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			ans=mrg(p[0]->ans,p[1]->ans);
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ans.mn[0]+=lz;
			p[ii]->ans.mn[1]-=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ans.mn[0]+=w;
			ans.mn[1]-=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			ans=mrg(p[0]->ans,p[1]->ans);
		}
	}
	val qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return val0;
		}
		else if(l>=lh&&r<=rh)
		{
			return ans;
		}
		else
		{
			blc();
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
	long long bl(long long x)
	{
		if(l==r)
		{
			return l;
		}
		else
		{
			blc();
			return p[min(p[1]->ans.mn[0],p[1]->ans.mn[1])<x]->bl(x);
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ii,u,k,p,z;
	val tmp;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sg.bd(0,n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			u=!(i%2)*2-1;
			sg.ud(1,i,k*u);
			p=sg.bl(0);
			tmp=sg.qr(p+1,i);
			for(ii=0;ii<2;ii++)
			{
				z+=tmp.c[ii]*!tmp.mn[ii];
			}
		}
		printf("%lld\n",z);
	}
}