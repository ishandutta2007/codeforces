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

	copy_n(istream_iterator<decltype(arr)::value_type>(cin), arr.size(), arr.begin());

	ranges::sort(arr);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	array<int, 3> cnt{};

	for (auto it: arr)
		cnt[it % cnt.size()]++;

	int add = 0;

	if (arr.size() == 1)
	{
		add = 0;
	}
	else if (arr.back() % 3 == 1 && arr[arr.size() - 2] != arr.back() - 1 && arr.front() != 1)
	{
		add = 0;
	}
	else if (auto zer = ranges::count(cnt, 0); zer == 0)
	{
		add = 1;
	}
	else if (arr.back() % 3 == 0 && zer != 2)
	{
		add = 1;
	}
	else if (zer == 1)
	{
		add = cnt[0] == 0 ? 1 : 0;
	}
	else
	{
		add = 0;
	}

	cout << (arr.back() + 2) / 3 + add << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
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