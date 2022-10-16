#include <bits/stdc++.h>

using namespace std;

const long long ma=2e5;
long long n,nn[2],lg2[200069],vl[2][200069],sq[200069];
vector<long long> al[200069];
bitset<200069> vtd,dh;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn[dh[x]]++;
	vl[dh[x]][nn[dh[x]]]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=!dh[x];
			dfs(l);
		}
	}
}

int main()
{
	long long t,rr,i,ii,k,l,e;
	
	for(i=1;i<=ma;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		dfs(1);
		for(i=n;i;i--)
		{
			if(i==n||lg2[i]!=lg2[i+1])
			{
				e=nn[1]>nn[0];
			}
			sq[vl[e][nn[e]]]=i;
			nn[e]--;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}