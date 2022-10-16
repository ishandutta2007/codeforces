#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<ll, ll>> arr(n);

	for (auto &it : arr)
		cin >> it.first >> it.second;

	for (int i = 0; i < arr.size(); i++)
		arr[i].second = min(arr[i].second, arr[(i + 1) % arr.size()].first);

	ll sum = 0, mb = numeric_limits<ll>::max();

	for (auto it : arr)
	{
		sum += it.first - it.second;
		mb = min(mb, it.second);
	}

	cout << sum + mb << endl;
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