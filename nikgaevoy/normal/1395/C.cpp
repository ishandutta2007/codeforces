#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<unsigned> a(n), b(m);

	for (auto &it : a)
		cin >> it;
	for (auto &it : b)
		cin >> it;

	unsigned mask = ~((1u << 9u) - 1), ans = 0;

	while (mask % 2 == 0)
	{
		mask /= 2;

		bool ok = true;

		for (auto q : a)
		{
			bool fnd = false;

			for (auto w : b)
				if (((q & w & mask) & ~ans) == 0)
				{
					fnd = true;
					break;
				}

			if (!fnd)
			{
				ok = false;
				break;
			}
		}

		if (!ok)
			ans |= (mask ^ (mask - 1)) & mask;
	}

	cout << ans << endl;
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