#include <bits/stdc++.h>

using namespace std;

long long n,nn,tg;
vector<long long> al[100069];
bitset<100069> vtd,spc[2];
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(spc[0][x])
	{
		tg=x;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				return;
			}
		}
	}
}

int main()
{
	long long t,rr,i,ii,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
			for(ii=0;ii<2;ii++)
			{
				spc[ii][i]=0;
			}
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&nn);
			for(i=0;i<nn;i++)
			{
				scanf("%lld",&k);
				spc[ii][k]=1;
			}
		}
		printf("B %lld\n",k);
		fflush(stdout);
		scanf("%lld",&k);
		r0=0;
		dfs(k);
		printf("A %lld\n",tg);
		fflush(stdout);
		scanf("%lld",&k);
		if(spc[1][k])
		{
			z=tg;
		}
		else
		{
			z=-1;
		}
		printf("C %lld\n",z);
		fflush(stdout);
	}
}