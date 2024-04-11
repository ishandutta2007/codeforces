#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069],pst[31],ls[31],dh[3000069],dp[3000069];
vector<long long> cd[3000069];

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l,mn=1e18;
	
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		mn=min(mn,dp[l]);
	}
	if(!sz)
	{
		dp[x]=0;
	}
	else
	{
		dp[x]=(sz-1<<dh[x]-1)+mn;
	}
}

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	nn=1;
	ls[30]=1;
	pst[30]=1;
	dh[1]=30;
	for(i=1;i<=n;i++)
	{
		for(j=29;j>=0;j--)
		{
			if(pst[j]<pst[j+1]||(a[i-1]&(1<<j))!=(a[i]&(1<<j)))
			{
				nn++;
				cd[ls[j+1]].push_back(nn);
				ls[j]=nn;
				pst[j]=i;
				dh[nn]=j;
			}
		}
	}
	dfs(1);
	printf("%lld\n",dp[1]);
}