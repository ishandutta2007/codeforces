#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
	{
		cin >> it;
		it--;
	}

	auto slv = [&n](auto beg, auto end) -> vector<bool> {
		vector<bool> used(n), ans(n);
		int mx = -1, i = 0;
		bool flag = true;

		for (auto it = beg; it != end; ++it, i++)
		{
			ans[i] = (flag && mx + 1 == i);

			mx = max(mx, *it);
			flag &= !used[*it];
			used[*it] = true;
		}

		return ans;
	};

	auto fv = slv(arr.begin(), arr.end()), rv = slv(arr.rbegin(), arr.rend());

	vector<pair<int, int>> ans;

	for (int i = 1; i < arr.size(); i++)
		if (fv[i] && rv[arr.size() - i])
			ans.emplace_back(i, arr.size() - i);

	cout << ans.size() << endl;

	for (auto it : ans)
		cout << it.first << ' ' << it.second << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}