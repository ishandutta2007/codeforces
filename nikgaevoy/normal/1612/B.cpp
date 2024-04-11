#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, a, b;

	cin >> n >> a >> b;
	a--;
	b--;

	assert(n % 2 == 0);

	vector<int> ans(n);

	iota(ans.rbegin(), ans.rend(), 0);

	if (a < b)
		swap(*(ans.rbegin() + a), *(ans.rbegin() + b));

	if (*min_element(ans.begin(), ans.begin() + ans.size() / 2) == a &&
	    *max_element(ans.begin() + ans.size() / 2, ans.end()) == b)
	{
		for (auto it: ans)
			cout << it + 1 << ' ';
		cout << endl;
	}
	else
		cout << -1 << endl;
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