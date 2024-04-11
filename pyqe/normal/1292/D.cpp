#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,nm=0,dr[5069],dh[10069],pd[5069],pr[5069],fq[10069],sbt[10069],sm=0,z=1e18;
vector<pair<long long,long long>> fz[5069],al[10069];
pair<long long,long long> sk[5069];
vector<long long> pst[5069];
bitset<10069> vtd;

void ae(long long x,long long y,long long w)
{
	al[x].push_back({y,w});
	al[y].push_back({x,w});
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=fq[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	z=min(z,sm);
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			nn+=sbt[x]-sbt[l];
			sm+=w*(nn-(n-nn));
			dfs(l);
			sm-=w*(nn-(n-nn));
			nn-=sbt[x]-sbt[l];
		}
	}
}

int main()
{
	long long i,j,k,l,w,ll,c,p=0,sz,bg,lca;
	
	for(i=2;i<=5000;i++)
	{
		if(fz[i].empty())
		{
			p++;
			for(j=i;j<=5000;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({p,c});
				dr[j]+=c;
			}
		}
	}
	nm=5000;
	for(i=1;i<=5000;i++)
	{
		sz=fz[i].size();
		lca=dh[i-1];
		if(sz)
		{
			bg=fz[i][sz-1].fr;
			for(j=1;j<bg;j++)
			{
				lca-=pd[j];
			}
		}
		for(j=0;j<sz;j++)
		{
			l=fz[i][j].fr;
			w=fz[i][j].sc;
			pd[l]+=w;
		}
		dh[i]=dh[i-1]+dr[i];
		l=0;
		for(;nn&&sk[nn].sc>=lca;nn--)
		{
			l=sk[nn].fr;
		}
		if(l)
		{
			nn++;
			sk[nn]={l,lca};
			sz=pst[l].size();
			if(lca<dh[pst[l][sz-1]])
			{
				nm++;
				dh[nm]=lca;
				pst[l].push_back(nm);
				sz++;
			}
			pr[i]=pst[l][sz-1];
		}
		nn++;
		sk[nn]={i,dh[i]};
		pst[i].push_back(i);
	}
	for(i=1;i<=5000;i++)
	{
		sz=pst[i].size();
		for(j=0;j<sz;j++)
		{
			l=pst[i][j];
			if(j)
			{
				ae(ll,l,dh[ll]-dh[l]);
			}
			ll=l;
		}
		if(pr[i])
		{
			ae(pst[i][sz-1],pr[i],dh[pst[i][sz-1]]-dh[pr[i]]);
		}
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		k+=!k;
		fq[k]++;
		sm+=dh[k];
	}
	bd(1);
	vtd.reset();
	nn=0;
	dfs(1);
	printf("%lld\n",z);
}