#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	auto check = [&](int t) -> string
	{
		auto iq = q;
		const auto tar = t;

		int cur;

		string str;

		for (cur = 0; t > 0 && cur + t < arr.size(); cur++)
			if (arr[cur] <= iq)
			{
				t--;
				str += '1';
			}
			else
				str += '0';

		for (; iq > 0 && cur < arr.size(); cur++)
			if (arr[cur] > iq)
			{
				iq--;
				t--;
				str += '1';
			}
			else
			{
				t--;
				str += '1';
			}

		str.resize(arr.size(), '0');

		return ranges::count(str, '1') >= tar ? str : "";
	};

	int l = 0, r = arr.size() + 1;

	while (l + 1 < r)
	{
		auto t = midpoint(l, r);

		if (auto w = check(t); !w.empty())
			l = ranges::count(w, '1');
		else
			r = t;
	}

	cout << check(l) << endl;
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