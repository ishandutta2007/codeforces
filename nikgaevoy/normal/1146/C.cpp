#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int n;

		cin >> n;

		int ans = 0;

		for (int i = 0;; i++)
		{
			vector<int> q0, q1;
			for (int j = 0; j < n; j++)
				if (j & (1 << i))
					q1.push_back(j);
				else
					q0.push_back(j);

			if (q0.empty() || q1.empty())
				break;

			cout << q0.size () << ' ' << q1.size ();
			for (auto it : q0)
				cout << ' ' << it + 1;
			for (auto it : q1)
				cout << ' ' << it + 1;
			cout << endl << flush;

			int qw;

			cin >> qw;

			ans = max (ans, qw);
		}

		cout << "-1 " << ans << endl;
	}
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve();

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}