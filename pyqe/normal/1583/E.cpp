#include <bits/stdc++.h>

using namespace std;

long long n,m,rr,nv=0,dsu[300069],fq[300069],vi[300069];
vector<long long> al[300069],sq[300069];
bool r0;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x,long long y)
{
	long long i,sz=al[x].size(),l;
	
	vi[x]=nv;
	if(x==y)
	{
		sq[rr].push_back(x);
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vi[l]<nv)
		{
			dfs(l,y);
			if(r0)
			{
				sq[rr].push_back(x);
				return;
			}
		}
	}
}

int main()
{
	long long t,i,k,l,sz,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(fd(k)!=fd(l))
		{
			dsu[fd(l)]=fd(k);
			al[k].push_back(l);
			al[l].push_back(k);
		}
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		fq[k]++;
		fq[l]++;
		r0=0;
		nv++;
		dfs(l,k);
	}
	for(i=1;i<=n;i++)
	{
		z+=fq[i]%2;
	}
	if(!z)
	{
		printf("YES\n");
		for(rr=1;rr<=t;rr++)
		{
			sz=sq[rr].size();
			printf("%lld\n",sz);
			for(i=0;i<sz;i++)
			{
				k=sq[rr][i];
				printf("%lld%c",k," \n"[i==sz-1]);
			}
		}
	}
	else
	{
		printf("NO\n%lld\n",z/2);
	}
}