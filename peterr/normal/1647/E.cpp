#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int LOGN = 30;
int nxt[LOGN][MAXN + 1];
int deg[MAXN + 1];
bool visited[MAXN + 1];
int ans[MAXN + 1];
int a[MAXN + 1];
int p[MAXN + 1];

int go(int v, int num)
{
	for (int i = 0; i < LOGN; i++)
	{
		if (num & (1 << i))
			v = nxt[i][v];
	}
	return v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int leaves = n;
	set<int> active;
	for (int i = 1; i <= n; i++)
	{
		active.insert(i);
		cin >> p[i];
		deg[p[i]]++;
		if (deg[p[i]] == 1)
			leaves--;
		nxt[0][i] = p[i];
	}
	for (int i = 1; i < LOGN; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		if (a[i] <= n)
			active.erase(a[i]);
	}
	int rounds = (mx - n) / leaves;
	for (int i = 1; i <= n; i++)
	{
		int v = go(i, rounds);
		if (!visited[v])
		{
			ans[i] = a[v];
			visited[v] = true;
		}
		else
		{
			ans[i] = *active.lower_bound(a[v]);
			active.erase(ans[i]);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
	return 0;
}