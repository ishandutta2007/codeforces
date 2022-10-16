#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> arr(n, pair<int, int>{-1, n});

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		arr[a].first++;
		arr[a].second = min(arr[a].second, (b - a + n) % n);
	}

	vector<int> dist(n);

	for (int i = 0; i < dist.size(); i++)
		dist[i] = arr[i].first * n + arr[i].second;

	for (int i = 0; i < n; i++)
	{
		int ans = 0;

		for (int j = 0; j < dist.size(); j++)
			if (arr[(j + i) % dist.size()].first >= 0)
				ans = max(ans, dist[(j + i) % dist.size()] + j);

		cout << ans << ' ';
	}
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}