#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	int any = 0, same = 0;

	vector<unordered_map<int, char>> gr(n);

	for (int i = 0; i < q; i++)
	{
		char type;

		cin >> type;

		if (type == '+')
		{
			int a, b;
			char c;

			cin >> a >> b >> c;
			a--;
			b--;

			gr[a][b] = c;

			if (gr[b].count(a))
			{
				any++;

				if (gr[b][a] == c)
					same++;
			}
		}
		else if (type == '-')
		{
			int a, b;

			cin >> a >> b;
			a--;
			b--;

			assert(gr[a].count(b));

			if (gr[b].count(a))
			{
				any--;

				if (gr[b][a] == gr[a][b])
					same--;
			}

			gr[a].erase(b);
		}
		else
		{
			assert(type == '?');

			int k;

			cin >> k;

			cout << ((k % 2 != 0 ? any : same) > 0 ? "yes" : "no") << '\n';
		}
	}
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