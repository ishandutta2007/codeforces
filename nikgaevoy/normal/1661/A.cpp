#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n), brr(n);

	for (auto &it: arr)
		cin >> it;
	for (auto &it: brr)
		cin >> it;

	ll ans = 0;

	for (auto pos: ranges::iota_view(1, ssize(arr)))
	{
		ans += min(abs(arr[pos] - arr[pos - 1]) + abs(brr[pos] - brr[pos - 1]),
		           abs(arr[pos] - brr[pos - 1]) + abs(brr[pos] - arr[pos - 1]));
	}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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