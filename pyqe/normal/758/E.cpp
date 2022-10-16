#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,wg[200069],po[200069],sbt[200069],cdh=0,tg[200069],lz[200069],sm[200069],dsu[200069],cd[200069],sq[200069],inf=1e18;
pair<long long,long long> ed[200069];
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd;
multiset<pair<long long,pair<long long,long long>>> ms[200069];
multiset<pair<long long,pair<long long,long long>>>::iterator it;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jn(long long x,long long y)
{
	long long p[2]={fd(x),fd(y)},e;
	pair<long long,long long> mxe=max(mp(cd[p[0]],0),{cd[p[1]],1});
	
	e=mxe.sc;
	for(it=ms[p[!e]].begin();it!=ms[p[!e]].end();it++)
	{
		ms[p[e]].insert(*it);
	}
	cd[p[e]]+=cd[p[!e]];
	dsu[p[!e]]=p[e];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,w,p,dd,ub,kk;
	
	vtd[x]=1;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			tg[l]=p;
			dfs(l);
			sbt[x]+=sbt[l]+wg[p];
			lz[x]+=lz[l];
			sm[x]+=sm[l];
			jn(x,l);
		}
	}
	cdh--;
	dd=po[tg[x]]-sbt[x];
	ub=wg[tg[x]]-1;
	for(kk=dd+lz[x];kk<0;)
	{
		if(ms[fd(x)].empty())
		{
			printf("-1\n");
			exit(0);
		}
		it=ms[fd(x)].begin();
		k=(*it).fr;
		p=(*it).sc.fr;
		l=(*it).sc.sc;
		ms[fd(x)].erase(it);
		w=min(l,-kk);
		l-=w;
		kk+=w;
		lz[x]+=w;
		sq[p]+=w;
		if(l)
		{
			ms[fd(x)].insert({k,{p,l}});
		}
	}
	k=min(dd+sm[x],ub);
	if(k)
	{
		ms[fd(x)].insert({-cdh,{tg[x],k}});
	}
	sm[x]+=k;
}

int main()
{
	long long i,k,l,w,p;
	
	scanf("%lld",&n);
	wg[0]=1;
	po[0]=1e18;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld%lld",&k,&l,wg+i,po+i);
		ed[i]={k,l};
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cd[i]=1;
	}
	dfs(1);
	printf("%lld\n",n);
	for(i=1;i<=n-1;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		printf("%lld %lld %lld %lld\n",k,l,wg[i]-sq[i],po[i]-sq[i]);
	}
}