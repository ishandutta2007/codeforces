#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,cr,z=0,sq[100069],inf=1e18;
vector<long long> al[100069],al2[100069];
bitset<100069> vtd,vtd2,dp;

void dfs(long long x)
{
	long long i,ii,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(dp[l])
			{
				dp[x]=0;
				z+=2;
				al2[x].push_back(l);
			}
		}
	}
	if(dp[x]&&x==1)
	{
		z+=2;
		al2[x].push_back(l);
	}
}

void trv(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd2[l])
		{
			trv(l);
		}
	}
	sq[x]=cr;
	cr=x;
}

void bt(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(!vtd2[x])
	{
		cr=x;
		trv(x);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bt(l);
		}
	}
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
	vtd.reset();
	bt(1);
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}