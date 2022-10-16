#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);

const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll x0, y0, ax, ay, bx, by;

	cin >> x0 >> y0 >> ax >> ay >> bx >> by;

	ll xs, ys, t;

	cin >> xs >> ys >> t;

	vector<pair<ll, ll>> arr;

	while (x0 < 4e16 && y0 < 4e16)
	{
		arr.emplace_back(x0, y0);

		x0 = ax * x0 + bx;
		y0 = ay * y0 + by;
	}

	int best = 0;

	const int bnd = 5;
	auto en = arr.size() > bnd ? arr.begin() + bnd : arr.end();

	sort(arr.begin(), en);

	do
	{
		for (int _ = 0; _ < 2; _++)
		{
			reverse(arr.begin(), arr.end());

			for (int i = 0; i < arr.size(); i++)
			{
				auto xc = xs;
				auto yc = ys;
				auto tc = t;
				int cur = 0;

				for (int j = i; tc > 0 && j < arr.size(); j++)
				{
					auto mv = abs(arr[j].first - xc) + abs(arr[j].second - yc);

					if (mv <= tc)
					{
						cur++;
						tc -= mv;

						xc = arr[j].first;
						yc = arr[j].second;
					}
				}

				best = max(best, cur);
			}
		}
	} while (next_permutation(arr.begin(), en));

	cout << best << endl;
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