#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	assert(n % 2 == 0);

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	auto mem = arr;

	vector<tuple<int, int, int>> ops;

	auto sub = [&](int a, int b)
	{
		assert(a < b);

		ops.emplace_back(2, a, b);

		arr[b] = arr[b] - arr[a];
	};

	auto add = [&](int a, int b)
	{
		assert(a < b);

		ops.emplace_back(1, a, b);

		arr[a] = arr[a] + arr[b];
	};

	for (int i = 0; i < arr.size(); i += 2)
	{
		int a = i;
		int b = i + 1;

		for (int j = 0; j < 2; j++)
		{
			add(a, b);
			sub(a, b);
			add(a, b);
		}
	}

	assert(ops.size() < 5000);

	for (int j = 0; j < arr.size(); j++)
		assert(arr[j] == -mem[j]);

	cout << ops.size() << endl;

	for (auto[t, a, b] : ops)
		cout << t << ' ' << a + 1 << ' ' << b + 1 << endl;
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