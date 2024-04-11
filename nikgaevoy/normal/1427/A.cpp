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

	auto check = [](const vector<int> &arr)
	{
		ll sum = 0;

		for (int it : arr)
		{
			sum += it;
			if (sum == 0)
				return false;
		}

		return true;
	};

	sort(arr.begin(), arr.end());

	if (check(arr))
	{
		cout << "YES\n";

		for (auto it : arr)
			cout << it << ' ';
		cout << '\n';

		return;
	}

	reverse(arr.begin(), arr.end());

	if (check(arr))
	{
		cout << "YES\n";

		for (auto it : arr)
			cout << it << ' ';
		cout << '\n';

		return;
	}

	cout << "NO\n";
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