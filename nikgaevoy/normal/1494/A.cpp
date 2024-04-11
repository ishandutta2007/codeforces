#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	char le = str.front();
	char ri = str.back();

	if (le == ri)
	{
		cout << "no" << endl;

		return;
	}

	char third = 'A' ^'B' ^'C' ^le ^ri;

	int type;

	if (count(str.begin(), str.end(), le) + count(str.begin(), str.end(), third) == count(str.begin(), str.end(), ri))
		type = 1;
	else if (count(str.begin(), str.end(), le) ==
	         count(str.begin(), str.end(), third) + count(str.begin(), str.end(), ri))
		type = -1;
	else
	{
		cout << "no" << endl;

		return;
	}

	int bal = 0;

	for (auto it : str)
	{
		if (it == le)
			bal++;
		else if (it == ri)
			bal--;
		else
			bal += type;

		if (bal < 0)
		{
			cout << "no" << endl;

			return;
		}
	}

	cout << "yes" << endl;
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