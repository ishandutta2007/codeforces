#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=26,ma=3e5,inf=1e18;
long long n,nn=0,sbt[300069],an[300069],dh[300069],fh[300069],pr[300069],a[300069];
vector<pair<long long,long long>> vl[300069];
vector<long long> al[300069];
multiset<long long> ms[300069];

struct trie
{
	long long od;
	trie *faf,*p[mm];
	
	void bd()
	{
		long long i;
		
		nn++;
		od=nn;
		faf=0;
		for(i=0;i<mm;i++)
		{
			p[i]=0;
		}
	}
}
tr,*ls[300069];

struct segtree
{
	long long l,r,mx;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx=-1;
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
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mx=w;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -1;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg[300069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={-inf,-1};
	
	sbt[x]=1;
	an[x]=x;
	fh[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		pr[l]=x;
		bd(l);
		sbt[x]+=sbt[l];
		mxe=max(mxe,{sbt[l],l});
	}
	e=mxe.sc;
	if(e+1)
	{
		an[l]=x;
		fh[x]=fh[l];
	}
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	an[x]=an[an[x]];
	if(an[x]==x)
	{
		sg[x].bd(dh[x],fh[x]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		anc(l);
	}
}

int main()
{
	long long t,rr,i,j,ky,k,l,w,sz,p,z;
	trie *tmp;
	string s;
	
	scanf("%lld%lld",&n,&t);
	tr.bd();
	for(i=1;i<=n;i++)
	{
		cin>>s;
		sz=s.length();
		for(j=1;j<=sz;j++)
		{
			k=s[j-1]-'a';
			vl[j].push_back({i,k});
		}
		ls[i]=&tr;
	}
	for(i=1;i<=ma;i++)
	{
		sz=vl[i].size();
		if(!sz)
		{
			break;
		}
		for(j=0;j<sz;j++)
		{
			k=vl[i][j].fr;
			w=vl[i][j].sc;
			if(!ls[k]->p[w])
			{
				ls[k]->p[w]=new trie;
				ls[k]->p[w]->bd();
				for(tmp=ls[k]->faf;tmp&&!tmp->p[w];tmp=tmp->faf);
				if(!tmp)
				{
					ls[k]->p[w]->faf=&tr;
				}
				else
				{
					ls[k]->p[w]->faf=tmp->p[w];
				}
				al[ls[k]->p[w]->faf->od].push_back(ls[k]->p[w]->od);
			}
			ls[k]=ls[k]->p[w];
		}
	}
	bd(1);
	anc(1);
	for(i=1;i<=n;i++)
	{
		k=ls[i]->od;
		ms[k].insert(0);
		sg[an[k]].ud(dh[k],0);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&ky);
		if(ky==1)
		{
			scanf("%lld%lld",&k,&l);
			p=ls[k]->od;
			ms[p].erase(ms[p].find(a[k]));
			a[k]=l;
			ms[p].insert(l);
			sg[an[p]].ud(dh[p],*prev(ms[p].end()));
		}
		else
		{
			cin>>s;
			sz=s.length();
			tmp=&tr;
			z=-1;
			for(i=1;i<=sz;i++)
			{
				k=s[i-1]-'a';
				for(;tmp&&!tmp->p[k];tmp=tmp->faf);
				if(!tmp)
				{
					tmp=&tr;
				}
				else
				{
					tmp=tmp->p[k];
				}
				for(p=tmp->od;p;p=pr[an[p]])
				{
					z=max(z,sg[an[p]].qr(dh[an[p]],dh[p]));
				}
			}
			printf("%lld\n",z);
		}
	}
}