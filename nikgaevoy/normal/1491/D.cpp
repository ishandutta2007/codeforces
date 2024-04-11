#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		unsigned a, b;

		cin >> a >> b;

		int bal = 0;
		bool good = true;

		for (unsigned j = 0; j < 30; j++)
		{
			if (a & b & (1u << j))
			{
				
			}
			else if (a & (1u << j))
			{
				bal++;
				good = false;
			}
			else if (b & (1u << j))
			{
				bal--;
				good = true;
			}

			if (bal < 0)
				break;
		}

		cout << (good && bal >= 0 ? "yes" : "no") << '\n';
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