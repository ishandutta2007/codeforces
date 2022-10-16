#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	if (str == string(str.size(), str.front()))
	{
		cout << str << endl;

		return;
	}

	// check unique char
	{
		map<char, int> cnt;

		for (auto it : str)
			cnt[it]++;

		for (auto[k, v] : cnt)
			if (v == 1)
			{
				swap(str.front(), str[str.find(k)]);
				sort(str.begin() + 1, str.end());

				cout << str << endl;

				return;
			}
	}

	assert(str.size() > 2);

	sort(str.begin(), str.end());

	auto b = 0;

	while (str[b] == str.front())
		b++;

	if (count(str.begin() + 2, str.end(), str.front()) > (str.size() - 2) / 2)
	{
		if (count(str.begin(), str.end(), str.front()) + count(str.begin(), str.end(), str[b]) == str.size())
		{
			sort(str.begin() + 1, str.end(), greater<char>());

			cout << str << endl;

			return;
		}

		swap(str[1], str[b]);

		sort(str.begin() + 2, str.end());

		b = 2;

		while (str[b] == str.front())
			b++;

		if (str[b] == str[1])
		{
			auto c = b;

			while (str[c] == str[1])
				c++;

			swap(str[b], str[c]);
		}

		cout << str << endl;

		return;
	}
	else
	{
		for (int i = 2; i < str.size() && str[i] == str.front(); i += 2)
			swap(str[i], str[b++]);

		cout << str << endl;

		return;
	}
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