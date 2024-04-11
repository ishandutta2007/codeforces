#include <bits/stdc++.h>
using namespace std;

int n, k;

vector <int> graf[1007];

long long dp[1007][1007];

long long dpl[1007][1007];

long long mod=1000000007;

void dod(long long &a, long long b)
{
	a=(a+b)%mod;
}

void dfs(int v, int oj)
{
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
		{
			swap(graf[v][i], graf[v].back());
			graf[v].pop_back();
			i--;
			continue;
		}
		dfs(graf[v][i], v);
	}
	for (int i=0; i<=n*2; i++)
		for (int j=0; j<=n*2; j++)
			dpl[i][j]=0;
	dpl[0][k+1]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		int u=graf[v][i];
		for (int j=0; j<=2*k+1; j++)
		{
			for (int l=0; l<=2*k+1; l++)
			{
				if (j+l+1<=2*k+1)
				{
					dod(dpl[i+1][min(j, l+1)], dpl[i][j]*dp[u][l]);
				}
				else
				{
					dod(dpl[i+1][max(j, l+1)], dpl[i][j]*dp[u][l]);
				}
			}
		}
	}
	for (int i=0; i<=2*k+1; i++)
	{
		dod(dp[v][i], dpl[graf[v].size()][i]);
		dod(dp[v][0], dpl[graf[v].size()][i]);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	dfs(1, 0);
	long long w=0;
	for (int i=0; i<=k; i++)
		dod(w, dp[1][i]);
	printf("%lld\n", w);
	return 0;
}