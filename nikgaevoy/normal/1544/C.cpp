#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> a(n), b(n);

	for (auto &it : a)
		cin >> it;
	for (auto &it : b)
		cin >> it;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	auto get_cnt = [&a]()
	{
		return a.size() - a.size() / 4;
	};

	ll asum = accumulate(a.rbegin(), a.rbegin() + get_cnt(), 0ll);
	ll bsum = accumulate(b.begin(), b.begin() + get_cnt(), 0ll);

	while (asum < bsum)
	{
		auto ol = get_cnt();
		a.push_back(100);
		b.push_back(0);
		auto cur = get_cnt();

		asum += 100;

		if (cur == ol)
			asum -= a[a.size() - 1 - cur];
		else
			bsum += b[ol];
	}

	cout << a.size() - n << endl;
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