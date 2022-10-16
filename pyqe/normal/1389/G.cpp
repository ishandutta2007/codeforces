#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,sa[300069],a[300069],wg[300069],dsu[300069],nr[300069],dp[300069],sq[300069],inf=1e18;
pair<long long,long long> ed[300069];
vector<long long> al[300069];
bitset<300069> vtd,vtd2,spc;
vector<pair<long long,long long>> alw[300069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}
void bgt(long long x,long long ls)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==ls)
		{
			continue;
		}
		if(!vtd[l])
		{
			nr[l]=nr[x]+1;
			bgt(l,x);
		}
		if(vtd2[fd(l)]&&nr[fd(l)]<=nr[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

void anc(long long x)
{
	long long i,sz=alw[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=alw[x][i].fr;
		if(!vtd[l])
		{
			anc(l);
			spc[x]=spc[x]|spc[l];
			if(!spc[l])
			{
				dsu[l]=x;
			}
		}
	}
}

void bd(long long x)
{
	long long i,sz=alw[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=alw[x][i].fr;
		w=alw[x][i].sc;
		if(spc[l]&&!vtd[l])
		{
			bd(l);
			dp[x]+=max(dp[l]+a[l]-w,0ll);
		}
	}
}

void trv(long long x,long long w)
{
	long long i,sz=alw[x].size(),l,ww;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=alw[x][i].fr;
		ww=alw[x][i].sc;
		if(spc[l])
		{
			if(!vtd[l])
			{
				trv(l,max(w+dp[x]-max(dp[l]+a[l]-ww,0ll)+a[x]-ww,0ll));
				sq[x]+=max(dp[l]+a[l]-ww,0ll);
			}
			else
			{
				sq[x]+=w;
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",sa+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",wg+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bgt(1,0);
	for(i=1;i<=m;i++)
	{
		k=fd(ed[i].fr);
		l=fd(ed[i].sc);
		if(k!=l)
		{
			alw[k].push_back({l,wg[i]});
			alw[l].push_back({k,wg[i]});
		}
	}
	for(i=1;i<=d;i++)
	{
		spc[fd(sa[i])]=1;
	}
	vtd.reset();
	anc(fd(sa[1]));
	for(i=1;i<=n;i++)
	{
		a[fd(i)]+=a[i]*(fd(i)!=i);
	}
	vtd.reset();
	bd(fd(sa[1]));
	vtd.reset();
	trv(fd(sa[1]),0);
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			sq[i]+=a[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[fd(i)]," \n"[i==n]);
	}
}