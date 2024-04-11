#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, l, r;

	cin >> n >> l >> r;

	assert(n % 2 == 0);
	assert(l + r == n);

	vector<int> arr(n);

	for (auto &it : arr)
	{
		cin >> it;
		it--;
	}

	vector<int> le(n), ri(n);

	for (int i = 0; i < l; i++)
		le[arr[i]]++;
	for (int i = l; i < n; i++)
		ri[arr[i]]++;

	for (int j = 0; j < n; j++)
	{
		auto t = min(le[j], ri[j]);

		le[j] -= t;
		ri[j] -= t;
	}

	if (l < r)
	{
		le.swap(ri);
		swap(l, r);
	}

	int ans = 0, add = (l - r) / 2;

	for (int j = 0; j < n; j++)
	{
		auto q = min(add, le[j] / 2);

		le[j] -= q * 2;
		add -= q;

		ans += q;
	}

	cout << ans + accumulate(ri.begin(), ri.end(), 0) + 2 * add << endl;
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