#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<ll> diff(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, d;

		cin >> a >> b >> d;
		a--;
		b--;

		diff[a] -= d;
		diff[b] += d;
	}

	vector<int> neg, pos;

	for (int i = 0; i < n; i++)
	{
		if (diff[i] < 0)
			neg.push_back(i);
		else if (diff[i] > 0)
			pos.push_back(i);
	}

	vector<vector<ll>> ans;

	while (!neg.empty())
	{
		auto d = min(-diff[neg.back()], diff[pos.back()]);

		ans.push_back({neg.back() + 1, pos.back() + 1, d});

		diff[neg.back()] += d;
		diff[pos.back()] -= d;

		while (!neg.empty() && diff[neg.back()] == 0)
			neg.pop_back();
		while (!pos.empty() && diff[pos.back()] == 0)
			pos.pop_back();
	}

	cout << ans.size() << endl;

	for (auto &row : ans)
	{
		for (auto it : row)
			cout << it << ' ';
		cout << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}