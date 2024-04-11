#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int dfs(std::vector<int>& f, std::vector<bool>& vis, int i, std::vector<int>& as, std::vector<std::vector<int> >& prev)
{
	if (i == -1)
		return 0;
	if (vis[i])
		return as[i];
	vis[i] = true;
	if (f[i] == 1)
		as[i] = dfs(f, vis, prev[0][i], as, prev) + 1;
	else
		as[i] = 1;
	return as[i];
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	vector<std::vector<int> > grid(m, std::vector<int> (n));
	vector<std::vector<int> > prev(m, std::vector<int> (n));
	/*
	2 2
	1 2
	2 1
	*/
	for (int i = 0; i < m; ++i)
	{
		int pr = -1;
		for (int j = 0; j < n; ++j)
		{
			int pos;
			cin >> pos; pos--;
			grid[i][pos] = j;
			prev[i][pos] = pr;
			pr = pos;
		}
	}
	std::vector<int> f(n);
	for (int i = 0; i < n; ++i)
	{
		bool ok = true;
		for (int j = 1; j < m; ++j)
			if (prev[j][i] != prev[j - 1][i])
				ok = false;
		if (ok)
			f[i] = 1;
		else
			f[i] = 0;
	}
	std::vector<bool> vis(n, false);
	std::vector<int> as(n);
	for (int i = 0; i < n; ++i)
		if (!vis[i])
			dfs(f, vis, i, as, prev);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += (as[i]);
	}
	cout << res;
}