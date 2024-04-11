#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,nm=0,ne=1,aa[200069],qv[500069],qp[500069],qe[300069],od[300069],dsu[500069],a[200069],pst[500069],sbt[500069],pr[500069][19],bl[500069],inf=1e18;
pair<long long,long long> ed[300069];
vector<long long> al[500069];
bitset<500069> vtd;

struct segtree
{
	long long l,r;
	pair<long long,long long> mx;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx={a[l],l};
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mx.fr=w;
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
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {-inf,-1};
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
sg;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	pst[x]=ne;
	if(x<=n)
	{
		a[ne]=aa[x];
		ne++;
		sbt[x]=1;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		pr[l][0]=x;
		for(j=1;j-1<bl[pr[l][j-1]];j++)
		{
			pr[l][j]=pr[pr[l][j-1]][j-1];
		}
		bl[l]=j;
		dfs(l);
		sbt[x]+=sbt[l];
	}
}

int main()
{
	long long t,rr,i,j,ii,ky,k,l,p;
	pair<long long,long long> z;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			nn++;
			qv[nn]=k;
			qp[nn]=rr;
		}
		else
		{
			nm++;
			qe[nm]=k;
			od[k]=rr;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(!od[i])
		{
			nm++;
			qe[nm]=i;
			od[i]=t+1;
		}
	}
	for(i=1;i<=n+m;i++)
	{
		dsu[i]=i;
	}
	for(i=m;i;i--)
	{
		k=ed[qe[i]].fr;
		l=ed[qe[i]].sc;
		if(fd(k)!=fd(l))
		{
			for(ii=0;ii<2;ii++)
			{
				al[n+qe[i]].push_back(fd(k));
				dsu[fd(k)]=n+qe[i];
				swap(k,l);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(fd(i));
		}
	}
	sg.bd(1,n);
	for(i=1;i<=nn;i++)
	{
		p=qv[i];
		for(j=bl[p]-1;j+1;j--)
		{
			if(j<bl[p]&&od[pr[p][j]-n]>qp[i])
			{
				p=pr[p][j];
			}
		}
		z=sg.qr(pst[p],pst[p]+sbt[p]-1);
		printf("%lld\n",z.fr);
		sg.ud(z.sc,0);
	}
}