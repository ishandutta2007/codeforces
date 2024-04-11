#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	k = n - k;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) 
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> d(n, -1);
	vector<int> s(n);
	std::function<void(int)> dfs = [&](int current) {
		s[current] = 1;
		for (int next : g[current]) 
			if (d[next] < 0)
			{
				d[next] = d[current] + 1;
				dfs(next);
				s[current] += s[next];
			}
	};
	d[0] = 0;
	dfs(0);
	vector<int> r(n);
	for (int i = 0; i < n; ++i)
		r[i] = s[i] - d[i];
	sort(r.begin(), r.end());
	long long ret = 0;
	for (int i = 0; i < k; ++i) 
		ret += r[n - 1 - i];
	cout << ret - k << endl;
	return 0;
}