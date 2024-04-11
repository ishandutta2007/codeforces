#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nm[2],nn,rt,pr[100069],sbt[100069],an[100069],dh[100069],cdh=0,rg[100069][2],udn[100069],pt[69];
vector<long long> al[100069],uds[100069];
vector<long long> bg[100069];
pair<pair<long long,long long>,long long> bkk[2][69];
pair<pair<long long,long long>,long long> bk[69];
bitset<69> inv;

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,sm;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
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
	void ud(long long x,long long w)
	{
		if(l>=x&&r<=x)
		{
			sm+=w;
		}
		else
		{
			long long ii;
			segtree tmp;
			
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				if(!(p[ii]->l>x||p[ii]->r<x))
				{
					tmp=*p[ii];
					p[ii]=new segtree;
					*p[ii]=tmp;
					p[ii]->ud(x,w);
				}
				sm+=p[ii]->sm;
			}
		}
	}
	long long qr(long long lh,long long rh)
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
			return p[0]->qr(lh,rh)+p[1]->qr(lh,rh);
		}
	}
};
vector<segtree> sg[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={-1e18,-1};
	
	sbt[x]=1;
	an[x]=x;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		bd(l);
		sbt[x]+=sbt[l];
		mxe=max(mxe,{sbt[l],l});
	}
	cdh--;
	e=mxe.sc;
	if(e!=-1)
	{
		an[e]=x;
	}
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	an[x]=an[an[x]];
	bg[an[x]].push_back(x);
	rg[an[x]][1]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		anc(l);
	}
	rg[an[x]][0]=dh[x];
}

long long qrr(long long x,long long pp,long long lh,long long rh)
{
	return sg[x][pp].qr(lh,rh)+rh-lh+1-sg[x][udn[x]-1].qr(lh,rh);
}

int main()
{
	long long t,rr,i,ii,ky,k,l,w,pp,p[2],e,kk,lb,rb,ww,sm,lh,rh,md,zz,z;
	pair<long long,long long> mxe;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
		if(!pr[i])
		{
			rt=i;
		}
		else
		{
			al[pr[i]].push_back({i});
		}
	}
	bd(rt);
	anc(rt);
	for(i=1;i<=n;i++)
	{
		if(an[i]==i)
		{
			sg[i].push_back(*(new segtree));
			uds[i].push_back(0);
			udn[i]++;
			sg[i][0].bd(rg[i][0],rg[i][1]);
		}
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			sg[an[k]].push_back(sg[an[k]][udn[an[k]]-1]);
			uds[an[k]].push_back(rr);
			udn[an[k]]++;
			sg[an[k]][udn[an[k]]-1].ud(dh[k],1);
		}
		else if(ky==2)
		{
			scanf("%lld%lld%lld",&l,&w,&pp);
			p[0]=k;
			p[1]=l;
			nm[0]=0;
			nm[1]=0;
			for(;an[p[0]]!=an[p[1]];)
			{
				mxe=max(mp(dh[an[p[0]]],0),{dh[an[p[1]]],1});
				e=mxe.sc;
				nm[e]++;
				bkk[e][nm[e]]={{dh[an[p[e]]],dh[p[e]]},an[p[e]]};
				p[e]=pr[an[p[e]]];
			}
			mxe=max(mp(dh[p[0]],0),{dh[p[1]],1});
			e=mxe.sc;
			nm[e]++;
			bkk[e][nm[e]]={{dh[p[!e]],dh[p[e]]},an[p[0]]};
			nn=0;
			for(ii=0;ii<2;ii++)
			{
				for(i=1+(nm[ii]-1)*ii;i!=(nm[ii]+1)*!ii;i+=!ii*2-1)
				{
					nn++;
					bk[nn]=bkk[ii][i];
					inv[nn]=!ii;
					kk=bk[nn].sc;
					pt[nn]=upper_bound(uds[kk].begin(),uds[kk].end(),pp)-uds[kk].begin()-1;
				}
			}
			w+=qrr(an[k],pt[1],dh[k],dh[k]);
			sm=0;
			for(i=1;i<=nn;i++)
			{
				kk=bk[i].sc;
				lb=bk[i].fr.fr;
				rb=bk[i].fr.sc;
				ww=qrr(kk,pt[i],lb,rb);
				if(w<=sm+ww)
				{
					break;
				}
				sm+=ww;
			}
			if(i>nn||(i==nn&&sm+ww==w&&qrr(an[l],pt[nn],dh[l],dh[l])))
			{
				printf("-1\n");
				continue;
			}
			for(lh=lb,rh=rb;lh<=rh;)
			{
				md=av(lh,rh);
				z=sm+qrr(kk,pt[i],!inv[i]?lb:md,!inv[i]?md:rb);
				if(z>=w)
				{
					zz=md;
				}
				if(z>=w^inv[i])
				{
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			printf("%lld\n",bg[kk][zz-dh[kk]]);
		}
	}
}