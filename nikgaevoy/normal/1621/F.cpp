#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ll sim(int a, int b, int c, int ca, int cb, vector<int> sz, int zer)
{
	ll ans = 0;

	while (zer > 0)
	{
		if (cb == 0 && b > c && !sz.empty() && sz.front() == 1)
		{
			zer--;
			ans -= c;
			sz.erase(sz.begin());
			cb++;
		}
		else if (ca > 0)
		{
			zer--;
			ans += a;
			ca--;

			for (auto &it: sz)
				if (it > 1)
				{
					it--;
					break;
				}
		}
		else if (b > c && zer > 0 && cb > 0)
		{
			zer--;
			ans -= c;
		}
		else
			break;

		if (cb > 0)
		{
			ans += b;
			cb--;
		}
		else
			break;
	}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, a, b, c;

	cin >> n >> a >> b >> c;

	string str;

	cin >> str;

	int ca = 0, cb = 0;

	for (int i = 1; i < str.size(); i++)
		if (str[i] == str[i - 1])
		{
			if (str[i] == '0')
				ca++;
			if (str[i] == '1')
				cb++;
		}

	vector<int> sz;

	for (int r, l = 0; l < str.size(); l = r)
	{
		for (r = l; r < str.size() && str[r] == str[l]; r++);

		if (str[l] == '0' && str[r] == '1' && l > 0 && str[l - 1] == '1')
			sz.push_back(r - l);
	}

	sort(sz.begin(), sz.end());

	auto zer = count(str.begin(), str.end(), '0');
	auto ans = sim(a, b, c, ca, cb, sz, zer);

	if (cb > 0)
		ans = max(ans, sim(a, b, c, ca, cb - 1, sz, zer) + b);

	cout << ans << endl;
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