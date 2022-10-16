#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n), trig(n);

	for (auto &it : arr)
		cin >> it;

	ll ans = accumulate(arr.begin(), arr.end(), 0ll);

	int q;

	cin >> q;

	vector<map<int, int>> ach(n);

	for (int i = 0; i < q; i++)
	{
		int s, t, u;

		cin >> s >> t >> u;
		s--;
		u--;

		if (ach[s].count(t))
		{
			auto cu = ach[s][t];

			if (--trig[cu] < arr[cu])
				ans++;

			ach[s].erase(t);
		}

		if (u != -1)
		{
			ach[s][t] = u;

			auto cu = ach[s][t];

			if (trig[cu]++ < arr[cu])
				ans--;
		}

		cout << ans << '\n';

#ifdef LOCAL
		cout << flush;
#endif
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

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}