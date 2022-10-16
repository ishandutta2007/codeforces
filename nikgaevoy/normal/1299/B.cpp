#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<complex<ll>> poly(n);

	for (auto &it : poly)
	{
		ll x, y;

		cin >> x >> y;

		it = {x, y};
	}

	if (poly.size() % 2 == 1)
	{
		cout << "no" << endl;

		return;
	}

	for (int i = 0; i < n / 2; i++)
		if (poly[i] + poly[i + n / 2] != poly.front() + poly[n / 2])
		{
			cout << "no" << endl;

			return;
		}

	cout << "yes" << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}