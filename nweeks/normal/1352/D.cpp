#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

ll solve(void)
{
	int n;
	cin >> n;
	vector<int> candies(n);
	for (auto &v : candies)
		cin >> v;

	int l(0), r(n-1);
	int nb_a(0), nb_b(0);
	int nb_tours(0);
	int prev_eaten(0);
	while (l <= r)
	{
		if (nb_tours%2==0)
		{
			int nb_manger(0);
			while (l <= r and prev_eaten >= nb_manger)
				nb_manger += candies[l++];
			prev_eaten = nb_manger;
			nb_a += nb_manger;
		}
		else
		{
			int nb_manger(0);
			while (l <= r and prev_eaten >= nb_manger)
				nb_manger += candies[r--];
			prev_eaten = nb_manger;
			nb_b += nb_manger;
		}
		nb_tours++;
	}
	cout << nb_tours << ' ' << nb_a << ' ' << nb_b << '\n';

	return 0;
}