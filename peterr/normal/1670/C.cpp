#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5;
int a[MAXN + 1];
int where_a[MAXN + 1];
int b[MAXN + 1];
int c[MAXN + 1];
bool visited[MAXN + 1];

bool dfs(int v)
{
	visited[v] = true;
	bool ans = c[v] > 0;
	if (!visited[where_a[b[v]]])
		ans = dfs(where_a[b[v]]) || ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(visited + 1, visited + n + 1, false);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			where_a[a[i]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
		}
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
				continue;
			if (!dfs(i) && a[i] != b[i])
			{
				ans = (int) ((long long) ans * 2 % MOD);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}