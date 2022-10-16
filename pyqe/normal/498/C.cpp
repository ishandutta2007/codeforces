#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,nm=0,mn,wg[469],inf=1e18;
pair<long long,pair<long long,long long>> fz[3069];
pair<long long,long long> ed[169];
vector<pair<long long,long long>> al[169];
bitset<169> vtd;
bool r0;

void ae(long long x,long long y,long long w)
{
	wg[nm+1]=w;
	wg[nm+2]=0;
	al[x].push_back({y,nm+1});
	al[y].push_back({x,nm+2});
	nm+=2;
}

void dfs(long long x,long long w)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	if(x==n+1)
	{
		r0=1;
		mn=w;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(wg[p]&&!vtd[l])
		{
			dfs(l,min(w,wg[p]));
			if(r0)
			{
				wg[p]-=mn;
				wg[p/2*2+1+p%2]+=mn;
				return;
			}
		}
	}
}

int main()
{
	long long i,j,k,l,w,c,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(j=2;j*j<=k;j++)
		{
			for(c=0;k%j==0;k/=j,c++);
			if(c)
			{
				nn++;
				fz[nn]={j,{i,c}};
			}
		}
		if(k>1)
		{
			nn++;
			fz[nn]={k,{i,1}};
		}
	}
	sort(fz+1,fz+nn+1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k%2==0)
		{
			swap(k,l);
		}
		ed[i]={k,l};
	}
	for(i=1;i<=nn;i++)
	{
		k=fz[i].fr;
		l=fz[i].sc.fr;
		w=fz[i].sc.sc;
		if(l%2)
		{
			ae(0,l,w);
		}
		else
		{
			ae(l,n+1,w);
		}
		if(i==nn||k!=fz[i+1].fr)
		{
			for(j=1;j<=m;j++)
			{
				k=ed[j].fr;
				l=ed[j].sc;
				ae(k,l,inf);
			}
			for(r0=1;r0;)
			{
				r0=0;
				vtd.reset();
				dfs(0,inf);
				z+=mn*r0;
			}
			for(j=0;j<=n+1;j++)
			{
				al[j].clear();
			}
			nm=0;
		}
	}
	printf("%lld\n",z);
}