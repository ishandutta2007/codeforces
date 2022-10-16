#include <bits/stdc++.h>

using namespace std;

long long n,rt,dg[100069],mn=1,mx;
vector<long long> al[100069];
bitset<100069> vtd;
bool cdis=0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(dg[x]==1&&cdis)
	{
		mn=3;
	}
	cdis^=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
	cdis^=1;
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
		dg[k]++;
		dg[l]++;
	}
	mx=n-1;
	for(i=1;i<=n;i++)
	{
		if(dg[i]==1)
		{
			rt=i;
			mx-=vtd[al[i][0]];
			vtd[al[i][0]]=1;
		}
	}
	vtd.reset();
	dfs(rt);
	printf("%lld %lld\n",mn,mx);
}