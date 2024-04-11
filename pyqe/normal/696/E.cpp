#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,fq[100069],pst[100069],sbt[100069],dh[100069],pr[100069],an[100069],fh[100069],sq[100069],zs;
vector<long long> al[100069],vl[100069];
bitset<100069> vtd;

struct segtree
{
	long long l,r,lz;
	pair<long long,long long> mne;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mne={0,0};
		lz=0;
		if(l<r)
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
			p[ii]->mne.fr+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,pair<long long,long long> w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mne.fr+=w.fr;
			mne.sc+=w.sc;
			lz+=w.fr;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mne=min(p[0]->mne,p[1]->mne);
		}
	}
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {inf,0};
		}
		else if(l>=lh&&r<=rh)
		{
			return mne;
		}
		else
		{
			blc();
			return min(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={-inf,-1};
	
	vtd[x]=1;
	n++;
	pst[x]=n;
	sbt[x]=1;
	an[x]=x;
	fh[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
			bd(l);
			sbt[x]+=sbt[l];
			mxe=max(mxe,{sbt[l],l});
		}
	}
	e=mxe.sc;
	if(e+1)
	{
		an[e]=x;
		fh[x]=fh[e];
	}
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(an[x]==x)
	{
		sg[x].bd(dh[x],fh[x]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			if(an[l]==x)
			{
				an[l]=an[x];
			}
			anc(l);
		}
	}
}

long long pth(long long x,long long y)
{
	pair<long long,long long> tmp,mne={inf,0};
	
	for(;an[x]!=an[y];x=pr[an[x]])
	{
		if(dh[an[x]]<dh[an[y]])
		{
			swap(x,y);
		}
		tmp=sg[an[x]].qr(dh[an[x]],dh[x]);
		tmp.fr+=sg[0].qr(pst[an[x]],pst[an[x]]).fr;
		mne=min(mne,tmp);
	}
	if(dh[x]>dh[y])
	{
		swap(x,y);
	}
	tmp=sg[an[x]].qr(dh[x],dh[y]);
	tmp.fr+=sg[0].qr(pst[an[x]],pst[an[x]]).fr;
	mne=min(mne,tmp);
	return mne.sc;
}

int main()
{
	long long t,rr,i,j,ky,k,l,w,e;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		vl[k].push_back(i);
		fq[k]++;
	}
	sg[0].bd(1,n);
	n=0;
	bd(1);
	vtd.reset();
	anc(1);
	for(i=1;i<=n;i++)
	{
		vl[i].push_back(inf);
		for(j=0;j<fq[i]-j;j++)
		{
			swap(vl[i][j],vl[i][fq[i]-j]);
		}
		sg[an[i]].ud(dh[i],dh[i],{vl[i][fq[i]],i});
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			scanf("%lld",&w);
			zs=0;
			for(;w;w--)
			{
				e=pth(k,l);
				if(!fq[e])
				{
					break;
				}
				zs++;
				sq[zs]=vl[e][fq[e]];
				sg[an[e]].ud(dh[e],dh[e],{vl[e][fq[e]-1]-vl[e][fq[e]],0});
				fq[e]--;
			}
			printf("%lld",zs);
			for(i=1;i<=zs;i++)
			{
				printf(" %lld",sq[i]);
			}
			printf("\n");
		}
		else
		{
			sg[0].ud(pst[k],pst[k]+sbt[k]-1,{l,0});
			if(an[k]!=k)
			{
				sg[an[k]].ud(dh[k],fh[k],{l,0});
			}
		}
	}
}