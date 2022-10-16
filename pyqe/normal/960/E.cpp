#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,a[200069],dh[200069],sbt[200069][3],pr[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x][2]++;
	sbt[x][dh[x]%2]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
			dfs(l);
			for(j=0;j<3;j++)
			{
				sbt[x][j]+=sbt[l][j];
			}
		}
	}
}

int main()
{
	long long i,j,k,l,sz,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]=(a[i]%dv+dv)%dv;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		z=(z+a[i]*n)%dv;
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			if(l!=pr[i])
			{
				z=(z+a[i]*(sbt[l][dh[i]%2]+dv-sbt[l][!(dh[i]%2)])%dv*(n-sbt[l][2]))%dv;
			}
			else
			{
				z=(z+a[i]*(sbt[1][dh[i]%2]+dv-sbt[i][dh[i]%2]+dv-sbt[1][!(dh[i]%2)]+sbt[i][!(dh[i]%2)])%dv*(sbt[i][2]))%dv;
			}
		}
	}
	printf("%lld\n",z);
}