#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 128;
const int INF = 1050000000;

int n, m;
int a[MAXN][MAXN];
int results;
int odd[MAXN];
int path[MAXN];
int dp[MAXN][MAXN];
int last[MAXN][MAXN];

void DepthFirstSearch(int depth)
{
	for (int i = 0; i < n; i++)
		dp[0][i] = (i == 0 ? 0 : INF);
	for (int k = 1; k <= m; k++)
	{
		for (int i = 0; i < n; i++)
		{
			dp[k][i] = INF;
			if (odd[i] < 0 || odd[i] == k % 2)
			{
				for (int j = 0; j < n; j++)
					if (i != j && dp[k - 1][j] + a[j][i] < dp[k][i])
					{
						dp[k][i] = dp[k - 1][j] + a[j][i];
						last[k][i] = j;
					}
			}
		}
	}
	if (dp[m][0] >= results)
	{
		return;
	}
	for (int i = 0, k = m; k > 0; k--)
	{
		path[k] = i;
		i = last[k][i];
	}
	path[0] = 0;
	int odd_pts = -1;
	for (int i = 0; i <= m; i++)
	{
		for (int j = i + 1; j <= m; j += 2)
		{
			if (path[i] == path[j])
			{
				odd_pts = path[i];
			}
		}
	}
	if (odd_pts < 0)
	{
		results = min(results, dp[m][0]);
		return;
	}
	if (depth == 10)
	{
		return;
	}
	odd[odd_pts] = 0;
	DepthFirstSearch(depth + 1);
	odd[odd_pts] = 1;
	DepthFirstSearch(depth + 1);
	odd[odd_pts] = -1;
}
int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	results = INF;
	for (int i = 0; i < n; i++)
	{
		odd[i] = -1;
	}
	odd[0] = 0;
	DepthFirstSearch(0);
	cout << results << endl;
	return 0;
}