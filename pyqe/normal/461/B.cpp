#include <bits/stdc++.h>

using namespace std;

long long n,sz=0,ckg=-1,dp[3][100069],z=1,pwk,dv=1e9+7;
bool bk[100069];
vector<long long> cd[100069],v;

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk*=pwk;
	pwk%=dv;
	if(y%2==1)
	{
		pwk*=x;
		pwk%=dv;
	}
	return pwk;
}

void dfs(long long x)
{
	if(x!=ckg&&bk[x])
	{
		dp[0][x]=0;
		dp[1][x]=1;
		dp[2][x]=1;
		return;
	}
	long long sz=cd[x].size(),i,k;
	
	dp[0][x]=1;
	for(i=0;i<sz;i++)
	{
		k=cd[x][i];
		dfs(k);
		dp[0][x]*=dp[0][k]+dp[1][k];
		dp[0][x]%=dv;
		dp[2][x]+=dp[2][k];
		dp[2][x]%=dv;
	}
	for(i=0;i<sz;i++)
	{
		k=cd[x][i];
		dp[1][x]+=dp[0][x]*pw((dp[0][k]+dp[1][k]),dv-2)%dv*dp[1][k]%dv;
		dp[1][x]%=dv;
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&k);
		cd[k].push_back(i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",bk+i);
		if(bk[i])
		{
			v.push_back(i);
			sz++;
		}
	}
	dfs(0);
	z*=dp[1][0];
	z%=dv;
	for(i=0;i<sz;i++)
	{
		ckg=v[i];
		dfs(ckg);
		z*=dp[0][ckg];
		z%=dv;
	}
	printf("%lld\n",z);
}