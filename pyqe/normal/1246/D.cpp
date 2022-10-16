#include <bits/stdc++.h>

using namespace std;

long long n,fh[100069],eu[100069],sq[1000069],zs=0;
vector<long long> al[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		bd(l);
		fh[x]=max(fh[x],fh[l]+1);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(fh[l]+1==fh[x])
		{
			swap(al[x][i],al[x][sz-1]);
			break;
		}
	}
}

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	n++;
	eu[n]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(i)
		{
			for(j=0;j<fh[al[x][i-1]]+1;j++)
			{
				zs++;
				sq[zs]=l;
			}
		}
		dfs(l);
	}
}

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&k);
		al[k].push_back(i);
	}
	bd(0);
	n=0;
	dfs(0);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",eu[i]," \n"[i==n]);
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}