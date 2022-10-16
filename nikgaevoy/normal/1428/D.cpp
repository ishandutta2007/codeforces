#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<int> two_three, three;
	vector<int> mp_dn(n, -1), mp_up(n, -1);

	for (int i = (int) arr.size() - 1; i >= 0; i--)
		if (arr[i] == 1)
		{
			two_three.push_back(i);
		}
		else if (arr[i] == 2)
		{
			if (two_three.empty())
			{
				cout << -1 << endl;

				return;
			}

			mp_dn[two_three.back()] = i;
			mp_dn[i] = two_three.back();
			two_three.pop_back();
			three.push_back(i);
		}
		else if (arr[i] == 3)
		{
			if (three.empty() && two_three.empty())
			{
				cout << -1 << endl;

				return;
			}

			auto &type = three.empty() ? two_three : three;

			mp_dn[i] = type.back();
			mp_up[type.back()] = i;
			type.pop_back();

			three.push_back(i);
		}

	int y = 0;

	vector<bool> used(n);

	vector<vector<int>> pos(n);

	function<void(int)> dfs = [&](int x)
	{
		assert(arr[x] != 0);

		if (used[x])
			return;
		used[x] = true;

		if (mp_dn[x] > x)
			pos[x].push_back(pos[mp_dn[x]][mp_dn[mp_dn[x]] == x ? 0 : 1]);
		else
			pos[x].push_back(y++);

		if (mp_up[x] != -1)
		{
			pos[x].push_back(y++);

			dfs(mp_up[x]);
		}

		if (mp_dn[x] != -1)
			dfs(mp_dn[x]);
	};

	for (int i = 0; i < arr.size(); i++)
		if (!used[i] && arr[i] == 1)
			dfs(i);

	vector<pair<int, int>> ans;

	for (int i = 0; i < pos.size(); i++)
		for (auto it : pos[i])
		{
			ans.emplace_back(i, it);
			assert(it < n);
		}

	assert(ans.size() <= 2 * n);

	cout << ans.size() << endl;

	for (const auto &it : ans)
		cout << n - it.second << ' ' << it.first + 1 << '\n';
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