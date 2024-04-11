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

	for (auto &it: arr)
		cin >> it;

	assert(is_sorted(arr.begin(), arr.end()));

	int ans = 0;

	for (int l = 0, r; l < ssize(arr); l = r)
	{
		for (r = l; r < ssize(arr) && arr[l] == arr[r]; r++);

		int cnt = r - l;
		int st = arr[l];
		auto bnd = st + 1;

		while (true)
		{
			auto q = ranges::lower_bound(arr, bnd);

			if (q == arr.end())
				break;

			cnt++;
			bnd = 2 * *q - st;
		}

		ans = max(ans, cnt);
	}

	cout << ssize(arr) - ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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