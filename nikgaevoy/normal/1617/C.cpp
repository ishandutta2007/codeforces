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

	set<int> perm;

	for (auto it: ranges::iota_view(1) | views::take(ssize(arr)))
		perm.insert(it);

	{
		vector<int> tmp;

		for (auto it: arr)
		{
			if (perm.contains(it))
				perm.erase(it);
			else
				tmp.push_back(it);
		}

		arr = move(tmp);
	}

	ranges::reverse(arr);

	for (auto it: perm)
	{
		auto val = arr.back();
		arr.pop_back();

		assert(it != val);

		if (val <= 2 * it)
		{
			cout << -1 << endl;

			return;
		}
	}

	cout << perm.size() << endl;
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