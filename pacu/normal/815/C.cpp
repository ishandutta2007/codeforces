#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N,B;
int c[5000],d[5000];
int x[5000];
int sz[5000];
int cid[5000];
int lst[5000][5001];
int lstSize[5000];
int dp[5000][5001];
int clist[5000][5000];
int cnum[5000];

bool cmpCost(int a,int b)
{
	return c[a]<c[b];
}

int main()
{
	scanf("%d %d",&N,&B);
	for(int i=0;i<N;i++)
		for(int j=0;j<=N;j++)
			dp[i][j] = B+1;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&c[i],&d[i]);
		d[i] = c[i]-d[i];
		if(i>0) scanf("%d",&x[i]);
		x[i]--;
		cid[i] = i;
	}
	for(int i=1;i<N;i++)
		clist[x[i]][cnum[x[i]]++] = i;
	sort(cid,cid+N,cmpCost);
	for(int i=0;i<N;i++)
		lst[i][lstSize[i]++] = 0;
	for(int i=0;i<N;i++)
	{
		int cur = cid[i];
		int j = cur;
		while(j != -1)
		{
			lst[j][lstSize[j]++] = c[cur];
			j = x[j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int k=1;k<lstSize[i];k++)
		{
			lst[i][k] += lst[i][k-1];
			if(lst[i][k] > B) lst[i][k] = B+1;
		}
		sz[i] = lstSize[i]-1;
	}
	for(int i=N-1;i>=0;i--)
	{
		if(cnum[i]==0)
		{
			dp[i][0] = 0;
			dp[i][1] = d[i];
		}
		else
		{
			int cmx = clist[i][0];
			for(int j=1;j<cnum[i];j++)
				if(sz[clist[i][j]] > sz[cmx])
					cmx = clist[i][j];
			int csz = sz[cmx];
			for(int j=0;j<=csz;j++)
				dp[i][j] = dp[cmx][j];
			for(int j=0;j<cnum[i];j++) if(clist[i][j]!=cmx)
			{
				int cur = clist[i][j];
				for(int k=csz+sz[cur];k>=0;k--)
					for(int l=max(0,k-csz);l<=sz[cur] && l<=k;l++)
						dp[i][k] = min(dp[i][k],dp[i][k-l]+dp[cur][l]);
				csz += sz[cur];
			}
			for(int j=csz+1;j>0;j--)
				dp[i][j] = dp[i][j-1] + d[i];
			for(int j=0;j<=csz+1;j++)
				dp[i][j] = min(dp[i][j],lst[i][j]);
		}
	}
	int ans = 0;
	for(int i=1;i<=N;i++)
		if(dp[0][i] <= B)
			ans = i;
	cout << ans << '\n';
}