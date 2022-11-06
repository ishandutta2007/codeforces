#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
vector<vector<int>> p;
bool seen[MAXN];

bool check(int n, int m, int x)
{
	fill(seen, seen + n, false);
	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (p[i][j] < x)
				continue;
			seen[j] = true;
			cnt++;
		}
		if (cnt >= 2)
			flag = true;
	}
	for (int i = 0; i < n; i++)
		if (!seen[i])
			return false;
	return flag;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		p = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> p[i][j];
			}
		}
		int ans = 1;
		for (int jump = 1E9; jump; jump >>= 1)
		{
			while (ans + jump <= 1E9 && check(n, m, ans + jump))
				ans += jump;
		}
		cout << ans << "\n";
	}
	return 0;
}