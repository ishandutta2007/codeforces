#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ma=360,aga[300069];
pair<double,double> a[300069];
double pi=acos(-1),sn[360],cs[360];

pair<double,double> mv(pair<double,double> p,pair<double,double> w,long long agl)
{
	p.fr+=w.fr;
	p.sc+=w.sc;
	return {p.fr*cs[agl]-p.sc*sn[agl],p.fr*sn[agl]+p.sc*cs[agl]};
}

struct segtree
{
	long long l,r,la;
	pair<double,double> lz;
	segtree *p[2];
	
	void ad(pair<double,double> w,long long agl)
	{
		if(l==r)
		{
			a[l]=mv(a[l],w,agl);
			aga[l]=(aga[l]+agl)%ma;
		}
		else
		{
			lz=mv(lz,{0,0},la);
			lz=mv(lz,w,(ma-la)%ma);
			la=(la+agl)%ma;
		}
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz={0,0};
		la=0;
		if(l!=r)
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void blc()
	{
		long long ii,iii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ad(lz,la);
		}
		lz={0,0};
		la=0;
	}
	void ud(long long lh,long long rh,pair<double,double> w,long long agl)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ad(w,agl);
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w,agl);
			}
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k,l;
	double agl;
	
	for(i=0;i<ma;i++)
	{
		agl=pi*i/180;
		sn[i]=sin(agl);
		cs[i]=cos(agl);
	}
	scanf("%lld%lld",&n,&t);
	for(i=0;i<=n;i++)
	{
		a[i]={i,0};
	}
	sg.bd(0,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			sg.ud(k,k,{0,0},0);
			sg.ud(k,n,{cs[aga[k]]*l,sn[aga[k]]*l},0);
		}
		else
		{
			sg.ud(k-1,k-1,{0,0},0);
			sg.ud(k,n,{-a[k-1].fr,-a[k-1].sc},(ma-l)%ma);
			sg.ud(k,n,{a[k-1].fr,a[k-1].sc},0);
		}
		sg.ud(n,n,{0,0},0);
		printf("%.10lf %.10lf\n",a[n].fr,a[n].sc);
	}
}