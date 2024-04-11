#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,mxn=6e5,a[300069],as[600069],p2[600069],pwk,dv=1e9+7;
pair<long long,long long> qq[300069];
map<long long,long long> fq,com;

struct segtree
{
	long long l,r,ln,sm,ps[2],z;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii;
		
		l=lh;
		r=rh;
		ln=0;
		sm=0;
		for(ii=0;ii<2;ii++)
		{
			ps[ii]=0;
		}
		z=0;
		if(l==r);
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ud(long long x)
	{
		long long ii;
		
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			ln^=1;
			sm=as[l]*ln;
			for(ii=0;ii<2;ii++)
			{
				ps[ii]=as[l]*ln;
			}
		}
		else
		{
			ln=0;
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x);
				ln+=p[ii]->ln;
				sm=(sm+p[ii]->sm)%dv;
			}
			z=p[0]->ps[0]*p[1]->ps[1]%dv;
			for(ii=0;ii<2;ii++)
			{
				ps[ii]=(p[ii]->ps[ii]+p[!ii]->ps[ii]*p2[p[ii]->ln])%dv;
				z=(z+p[ii]->z*p2[p[!ii]->ln])%dv;
			}
		}
	}
}
sg;

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

int main()
{
	long long t,rr,i,k,l,dn;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k*mxn+fq[k];
		fq[k]++;
		as[i]=a[i];
	}
	scanf("%lld",&t);
	p2[0]=1;
	for(i=1;i<=n+t;i++)
	{
		p2[i]=p2[i-1]*2%dv;
	}
	dn=pw(p2[n],dv-2);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={k,l*mxn+fq[l]};
		fq[l]++;
		as[n+rr]=qq[rr].sc;
	}
	sort(as+1,as+n+t+1);
	for(i=1;i<=n+t;i++)
	{
		com[as[i]]=i;
		as[i]/=mxn;
	}
	sg.bd(1,n+t);
	for(i=1;i<=n;i++)
	{
		a[i]=com[a[i]];
		sg.ud(a[i]);
	}
	for(rr=0;rr<=t;rr++)
	{
		if(rr)
		{
			qq[rr].sc=com[qq[rr].sc];
			k=qq[rr].fr;
			l=qq[rr].sc;
			sg.ud(a[k]);
			a[k]=l;
			sg.ud(l);
		}
		printf("%lld\n",sg.z*dn%dv);
	}
}