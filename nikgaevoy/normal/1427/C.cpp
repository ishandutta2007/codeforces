#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int r, n;

	cin >> r >> n;

	vector<tuple<int, int, int>> arr(n);

	for (auto &it : arr)
	{
		int t, x, y;

		cin >> t >> x >> y;

		it = {t, x, y};
	}

	arr.insert(arr.begin(), {0, 1, 1});

	vector<int> dp(arr.size(), -1);
	dp.front() = 0;

	auto check = [](const auto &x, const auto &y)
	{
		int f, a, b;
		int t, c, d;

		tie(f, a, b) = x;
		tie(t, c, d) = y;

		return (t - f) >= abs(a - c) + abs(b - d);
	};

	for (int i = 0; i + 1 < dp.size(); i++)
		if (dp[i] >= 0)
			for (int j = i + 1; j < arr.size() && j < i + 4 * r; j++)
				if (check(arr[i], arr[j]))
					dp[j] = max(dp[j], dp[i] + 1);

	cout << *max_element(dp.begin(), dp.end()) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}