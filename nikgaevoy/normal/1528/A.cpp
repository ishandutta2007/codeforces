#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


struct dfs
{
	const vector<vector<int>> &gr;
	const vector<pair<int, int>> &arr;

	pair<ll, ll> operator()(int v = 0, int p = -1)
	{
		pair<ll, ll> ans;

		for (auto it : gr[v])
			if (it != p)
			{
				auto q = (*this)(it, v);

				ans.first += max(abs(arr[v].first - arr[it].first) + q.first,
				                 abs(arr[v].first - arr[it].second) + q.second);
				ans.second += max(abs(arr[v].second - arr[it].first) + q.first,
				                  abs(arr[v].second - arr[it].second) + q.second);
			}

		return ans;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
		cin >> it.first >> it.second;

	for (int i = 1; i < n; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	auto ans = dfs{gr, arr}(0);

	cout << max(ans.first, ans.second) << endl;
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
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}