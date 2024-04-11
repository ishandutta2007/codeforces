#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[200069][6],dp[200069][6],z=0;
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,j,r,sz=al[x].size(),l,tf[6],td[6];
	
	vtd[x]=1;
	fq[x][d]=1;
	dp[x][d]=-1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=1;j<=d;j++)
			{
				tf[j]=0;
				td[j]=0;
			}
			for(j=1;j<=d;j++)
			{
				tf[j%d+1]+=fq[l][j];
				td[j%d+1]+=dp[l][j]+fq[l][j]*(j/d);
			}
			for(j=1;j<=d;j++)
			{
				fq[l][j]=tf[j];
				dp[l][j]=td[j];
			}
			for(j=1;j<=d;j++)
			{
				for(r=1;r<=d;r++)
				{
					z+=dp[x][j]*fq[l][r]+dp[l][r]*fq[x][j]+fq[x][j]*fq[l][r]*((j+r-1)/d+1);
				}
			}
			for(j=1;j<=d;j++)
			{
				fq[x][j]+=fq[l][j];
				dp[x][j]+=dp[l][j];
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld",z);
}