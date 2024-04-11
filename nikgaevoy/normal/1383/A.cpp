#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string a, b;

	cin >> a >> b;

	assert(a.size() == b.size());

	array<array<int, 20>, 20> cnt{};

	for (int i = 0; i < a.size(); i++)
		cnt[a[i] - 'a'][b[i] - 'a']++;

	for (int i = 0; i < cnt.size(); i++)
		for (int j = 0; j < i; j++)
			if (cnt[i][j] > 0)
			{
				cout << -1 << endl;

				return;
			}

	int ans = 0;

	for (int i = 0; i < cnt.size(); i++)
	{
		int st = i + 1;

		while (st < cnt.size() && cnt[i][st] == 0)
			st++;

		if (st < cnt.size())
		{
			ans++;

			for (int j = st; j < cnt.size(); j++)
			{
				cnt[st][j] += cnt[i][j];
				cnt[i][j] = 0;
			}
		}
	}

	cout << ans << endl;
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