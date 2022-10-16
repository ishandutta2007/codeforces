#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	if (count(str.begin(), str.end(), 'M') != n / 3)
	{
		cout << "NO" << endl;

		return;
	}

	int t = 0, tm = 0, tmt = 0;

	for (auto it : str)
	if (it == 'T')
	{
		if (tm > 0)
		{
			tm--;
			tmt++;
		}
		else
			t++;
	}
	else
	{
		if(t > 0)
		{
			t--;
			tm++;
		}
		else if (tmt > 0)
		{
			tmt--;
			tm++;
			t++;
			t--;
			tm++;
		}
		else
		{
			cout << "NO" << endl;

			return;
		}
	}

	cout << (tmt == n / 3 ? "YES" : "NO") << endl;
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