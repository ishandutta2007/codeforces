#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());

	for (int l = 0, r; l < arr.size(); l = r)
	{
		for (r = l; r < arr.size() && arr[l].first == arr[r].first; r++);

		array<int, 2> need{}, have{};

		for (int i = l; i < r; i++)
		{
			need[arr[i].second % 2]++;
			have[i % 2]++;
		}

		if (need != have)
		{
			cout << "NO" << endl;

			return;
		}
	}

	cout << "YES" << endl;
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