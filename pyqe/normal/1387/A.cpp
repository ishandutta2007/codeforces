#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,rt,sm,sm2,vtd[100069],vl[100069],sq[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> py;
bool bad,e;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	nn++;
	vl[nn]=sq[x]*(py[x]*2-1);
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			py[l]=py[x]^1;
			sq[l]=w-sq[x];
			dfs(l);
		}
		else if(py[l]==py[x])
		{
			rt=l;
			bad=0;
			sm=0;
			sm2=0;
			e=0;
		}
		if(rt)
		{
			if(!bad)
			{
				sm+=w;
				sm2+=w*e;
				e^=1;
			}
			if(x==rt)
			{
				sq[x]=sm/2-sm2;
				bad=1;
			}
			return;
		}
	}
}

void trv(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=2;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(vtd[l]!=2)
		{
			sq[l]=w-sq[x];
			trv(l);
		}
		else if(sq[l]!=w-sq[x])
		{
			printf("NO\n");
			exit(0);
		}
	}
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		w*=2;
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			rt=0;
			nn=0;
			dfs(i);
			if(!rt)
			{
				rt=i;
				sort(vl+1,vl+nn+1);
				sq[i]=vl[(nn+1)/2];
			}
			trv(rt);
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		if(sq[i]<0)
		{
			printf("-");
		}
		printf("%lld",abs(sq[i])/2);
		if(sq[i]%2)
		{
			printf(".5");
		}
		printf("%c"," \n"[i==n]);
	}
}