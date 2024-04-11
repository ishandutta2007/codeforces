#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];
vector<long long> al[100069];
bitset<100069> vtd;
array<long long,40> dp[100069],a0;
vector<array<long long,40>> dpl[100069];

void bd(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x][0]=a[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			for(j=0;j<d*2;j++)
			{
				dp[x][(j+1)%(d*2)]^=dp[l][j];
			}
		}
	}
}

void bd2(long long x,array<long long,40> w)
{
	long long i,j,sz=al[x].size(),l;
	array<long long,40> ww;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dpl[x].push_back(dp[l]);
			ww=dp[x];
			for(j=0;j<d*2;j++)
			{
				ww[(j+1)%(d*2)]^=dp[l][j]^w[j];;
			}
			bd2(l,ww);
		}
		else
		{
			dpl[x].push_back(w);
		}
	}
}

int main()
{
	long long i,j,r,k,l,sz,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	bd(1);
	vtd.reset();
	bd2(1,a0);
	for(i=1;i<=n;i++)
	{
		z=0;
		sz=dpl[i].size();
		for(j=0;j<sz;j++)
		{
			for(r=d;r<d*2;r++)
			{
				z^=dpl[i][j][r-1];
			}
		}
		printf("%lld%c",(long long)!!z," \n"[i==n]);
	}
}