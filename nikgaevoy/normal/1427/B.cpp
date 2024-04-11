#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	string str;

	cin >> n >> k >> str;

	if (str.find('W') == string::npos)
	{
		cout << max(0, k * 2 - 1) << '\n';

		return;
	}

	int cl = count(str.begin(), str.end(), 'L');

	if (k >= cl)
	{
		cout << max(0, n * 2 - 1) << '\n';

		return;
	}

	vector<int> sz;

	for (int l = str.find('W'), r; l < str.size(); l = r)
	{
		for (r = l + 1; r < str.size() && str[r] == 'L'; r++);

		if (r != str.size() && r - l > 1)
			sz.push_back(r - l - 1);
	}

	sort(sz.begin(), sz.end(), greater<int>());

	int ans = 0;

	for (int i = 0; i < str.size(); i++)
		if (str[i] == 'W')
			ans += (i > 0 && str[i - 1] == 'W' ? 2 : 1);

	while (!sz.empty() && k >= sz.back())
	{
		ans += 2 * sz.back() + 1;
		k -= sz.back();
		sz.pop_back();
	}

	ans += 2 * k;

	cout << ans << '\n';
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