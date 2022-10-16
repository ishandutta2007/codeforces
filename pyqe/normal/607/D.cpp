#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=1,a[200069],pr[200069],pst[200069],sbt[200069],wg[200069],pwk,dv=1e9+7;
vector<long long> al[200069];
pair<long long,long long> qq[200069];

struct segtree
{
	long long l,r,sm,ml,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		lz=1;
		if(l==r)
		{
			ml=1;
		}
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
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->sm=p[ii]->sm*lz%dv;
			p[ii]->ml=p[ii]->ml*lz%dv;
			p[ii]->lz=p[ii]->lz*lz%dv;
		}
		lz=1;
	}
	void ad(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm=(sm+w)%dv;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ad(x,w);
			}
			sm=(p[0]->sm+p[1]->sm)%dv;
		}
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm=sm*w%dv;
			ml=ml*w%dv;
			lz=lz*w%dv;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			sm=(p[0]->sm+p[1]->sm)%dv;
		}
	}
	long long qp(long long x)
	{
		if(l>x||r<x)
		{
			return 0;
		}
		else if(l>=x&&r<=x)
		{
			return ml;
		}
		else
		{
			blc();
			return p[0]->qp(x)+p[1]->qp(x);
		}
	}
	long long qs(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			blc();
			return (p[0]->qs(lh,rh)+p[1]->qs(lh,rh))%dv;
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

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	n++;
	pst[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		sbt[x]+=sbt[l];
	}
}

int main()
{
	long long t,rr,i,ky,k;
	
	scanf("%lld%lld",a+1,&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			n++;
			scanf("%lld",a+n);
			pr[n]=k;
			al[k].push_back(n);
			qq[rr]={ky,n};
		}
		else
		{
			qq[rr]={ky,k};
		}
	}
	n=0;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		wg[i]=1;
	}
	sg.bd(0,n);
	sg.ad(pst[1],a[1]);
	for(rr=1;rr<=t;rr++)
	{
		ky=qq[rr].fr;
		k=qq[rr].sc;
		if(ky==1)
		{
			sg.ad(pst[k],a[k]*sg.qp(pst[k])%dv);
			sg.ud(pst[pr[k]],pst[pr[k]]+sbt[pr[k]]-1,(wg[pr[k]]+1)*pw(wg[pr[k]],dv-2)%dv);
			wg[pr[k]]++;
		}
		else
		{
			printf("%lld\n",sg.qs(pst[k],pst[k]+sbt[k]-1)*pw(sg.qp(pst[pr[k]]),dv-2)%dv);
		}
	}
}