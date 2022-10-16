#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int test;
	cin >> test;

	int n, m;
	ll t;

	while (cin >> n >> m >> t)
	{
		vector<int> p(n);
		for (int &x : p)
			cin >> x;

		const int bound = *max_element(p.begin(), p.end()) + 1;

		auto check = [&] (int d)
		{
			if (d == bound)
				return pair<int, bool>(-1, false);

			ll last = 0, sum_t = 0;
			int ptr = 0;
			bool good = true;
			int done = 0;

			for (int x : p)
			{
				if (x <= d)
				{
					if (ptr == m)
					{
						sum_t += last;
						ptr = 0;
						last = 0;
					}

					{
						sum_t += x;
						last += x;
						ptr++;

						if (sum_t > t)
							good = false;
						else
							done++;
					}
				}
			}

			return pair<int, bool>(done, good);
		};

		int left = 0, right = bound;
		while (right - left > 1)
		{
			int mid = (left + right) / 2;
			if (check(mid).second)
				left = mid;
			else
				right = mid;
		}

		int ans = -1, d = -1;
		for (int i = left; i <= right; i++)
		{
			int cur = check(i).first;
			if (ans < cur)
			{
				ans = cur;
				d = i;
			}
		}

		if (d > t)
			d = t;

		cout << ans << ' ' << d << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}