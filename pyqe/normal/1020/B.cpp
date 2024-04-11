#include <bits/stdc++.h>

using namespace std;

long long n,cr,sq[100069];
vector<long long> al[100069];
bitset<100069> vtd,vtd2,spc;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			r0=1;
		}
		if(r0)
		{
			spc[x]=1;
			return;
		}
	}
	vtd2[x]=0;
}

void fl(long long x)
{
	long long i,sz=al[x].size(),l;
	
	sq[x]=cr;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!spc[l])
		{
			fl(l);
		}
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		al[k].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			r0=0;
			dfs(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(spc[i])
		{
			cr=i;
			fl(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}