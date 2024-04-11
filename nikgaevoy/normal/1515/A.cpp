#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


bool check(const vector<int> &arr, int x)
{
	int sum = 0;

	for (auto it : arr)
	{
		sum += it;

		if (sum == x)
			return false;
	}

	return true;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, x;

	cin >> n >> x;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	if (accumulate(arr.begin(), arr.end(), 0) == x)
	{
		cout << "NO\n";

		return;
	}

	cout << "YES\n";

	while (!check(arr, x))
		shuffle(arr.begin(), arr.end(), mt);

	for (auto it : arr)
		cout << it << ' ';
	cout << endl;
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

	cout << setprecision((int)floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}