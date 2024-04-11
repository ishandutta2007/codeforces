#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,st,dsu[1000069],dh[1000069],wg[1000069],dp[1000069];
pair<pair<long long,long long>,long long> ed[1000069];
vector<pair<long long,long long>> al[1000069];
bitset<1000069> vtd,vtd2;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void scc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			scc(l);
		}
		if(vtd2[fd(l)]&&dh[fd(l)]<dh[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			bd(l);
		}
		dp[x]=max(dp[x],dp[l]+w);
	}
	dp[x]+=wg[x];
}

int main()
{
	long long i,k,l,w,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={{k,l},w};
		al[k].push_back({l,w});
	}
	scanf("%lld",&st);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			scc(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		al[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr.fr;
		l=ed[i].fr.sc;
		w=ed[i].sc;
		if(fd(k)==fd(l))
		{
			for(lh=1,rh=w+1;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(md*(md-1)/2<=w)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			wg[fd(k)]+=w*zz-(zz+1)*zz*(zz-1)/6;
		}
		else
		{
			al[fd(k)].push_back({fd(l),w});
		}
	}
	vtd.reset();
	bd(fd(st));
	printf("%lld\n",dp[fd(st)]);
}