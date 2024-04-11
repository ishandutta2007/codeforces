#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	ll ans = 0;

	vector<int> free_diff(arr.size() + 2);
	int cur_free = 0;
	ll prev_free = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		cur_free += free_diff[i];

		free_diff[i + 2]++;
		free_diff[min((int)arr.size() + 1, i + arr[i] + 1)]--;

		ll free = cur_free + prev_free;

		ans += max(0ll, (arr[i] - 1) - free);

		prev_free = max(0ll, free - (arr[i] - 1));
	}

	cout << ans << endl;
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