#include <bits/stdc++.h>

using namespace std;

long long n,sbt[5069],sq[5069],zs=0;
vector<long long> al[5069],cd[5069];
bitset<5069> vtd,sb,pb;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			cd[x].push_back(l);
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
	sb.reset();
	sb[0]=1;
	sz=cd[x].size();
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		sb|=sb<<sbt[l];
	}
	pb|=sb;
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<n-1;i++)
	{
		pb[i]=pb[i]|pb[n-1-i];
		if(pb[i])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i],n-1-sq[i]);
	}
}