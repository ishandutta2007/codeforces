#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069][3],dp[200069][3],z=0;
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,ii,iii,sz=al[x].size(),l,tf[3],td[3];
	
	vtd[x]=1;
	fq[x][2]=1;
	dp[x][2]=-1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(ii=1;ii<=2;ii++)
			{
				tf[ii]=0;
				td[ii]=0;
			}
			for(ii=1;ii<=2;ii++)
			{
				tf[ii%2+1]+=fq[l][ii];
				td[ii%2+1]+=dp[l][ii]+fq[l][ii]*(ii/2);
			}
			for(ii=1;ii<=2;ii++)
			{
				fq[l][ii]=tf[ii];
				dp[l][ii]=td[ii];
			}
			for(ii=1;ii<=2;ii++)
			{
				for(iii=1;iii<=2;iii++)
				{
					z+=dp[x][ii]*fq[l][iii]+dp[l][iii]*fq[x][ii]+fq[x][ii]*fq[l][iii]*((ii+iii-1)/2+1);
				}
			}
			for(ii=1;ii<=2;ii++)
			{
				fq[x][ii]+=fq[l][ii];
				dp[x][ii]+=dp[l][ii];
			}
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
	printf("%lld",z);
}