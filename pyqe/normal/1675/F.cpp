#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,st,fn,sbt[200069],dh[200069],z;
bitset<200069> spc,vtd;
vector<long long> al[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=spc[x];
	if(x==fn)
	{
		z-=dh[x];
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
			z+=2*(sbt[l]&&d2-sbt[l]);
		}
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&st,&fn);
		for(i=1;i<=n;i++)
		{
			spc[i]=0;
			al[i].clear();
			vtd[i]=0;
		}
		spc[st]=1;
		spc[fn]=1;
		d2=1+(st!=fn);
		for(i=0;i<d;i++)
		{
			scanf("%lld",&k);
			d2+=!spc[k];
			spc[k]=1;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		z=0;
		dh[st]=0;
		dfs(st);
		printf("%lld\n",z);
	}
}