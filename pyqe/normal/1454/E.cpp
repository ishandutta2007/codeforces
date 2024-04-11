#include <bits/stdc++.h>

using namespace std;

long long n,nn,ex[200069];
vector<long long> al[200069];
bitset<200069> vtd,spc;
bool r0,bad;

void dfs(long long x,long long ls)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l,x);
		}
		else if(l!=ls)
		{
			nn++;
			ex[nn]=l;
			spc[l]=1;
			r0=1;
			bad=0;
		}
		if(r0)
		{
			if(x==ex[1])
			{
				bad=1;
			}
			if(!bad)
			{
				nn++;
				ex[nn]=x;
				spc[x]=1;
			}
			return;
		}
	}
}

long long trv(long long x)
{
	long long i,sz=al[x].size(),l,sm=1;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!spc[l]&&!vtd[l])
		{
			sm+=trv(l);
		}
	}
	return sm;
}

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
			spc[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		nn=0;
		r0=0;
		dfs(1,0);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		z=n*(n-1);
		for(i=1;i<=nn;i++)
		{
			k=trv(ex[i]);
			z-=k*(k-1)/2;
		}
		printf("%lld\n",z);
	}
}