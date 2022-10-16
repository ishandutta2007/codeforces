#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> pos(n + 1);
	pos.front() = {0, 0};

	for (int i = 0; i < 2 * n; i++)
	{
		int t;

		cin >> t;

		pos[t].push_back(i);
	}

	for (auto &row : pos)
		sort(row.begin(), row.end());

	ll ans = 0;

	for (int i = 1; i < pos.size(); i++)
		ans += abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]);

	cout << ans << endl;
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