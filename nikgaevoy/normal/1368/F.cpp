#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	int k = 1;

	auto get = [n](int k)
	{
		vector<bool> should(n);

		for (int i = 0; i < should.size(); i++)
			should[i] = i % k > 0;

		return count(should.begin() + k, should.end(), true);
	};

	for (int i = 1; i <= n; i++)
		if (get(i) > get(k))
			k = i;

	vector<bool> should(n), cur(n);

	for (int i = 0; i < should.size(); i++)
		should[i] = i % k > 0;

	cerr << k << ' ' << get(k) << endl;

	while (count(cur.begin(), cur.end(), true) < get(k))
	{
		vector<int> add;

		for (int i = 0; i < n; i++)
			if (should[i] && !cur[i])
				add.push_back(i);

		shuffle(add.begin(), add.end(), mt);

		assert(add.size() >= k);

		cout << k;

		for (int i = 0; i < k; i++)
		{
			cout << ' ' << add[i] + 1;
			cur[add[i]] = true;
		}
		cout << endl << flush;

		int x;

		cin >> x;
		x--;

		if (x + k <= cur.size())
		{
			fill(cur.begin() + x, cur.begin() + x + k, false);
		}
		else
		{
			fill(cur.begin() + x, cur.end(), false);
			fill(cur.begin(), cur.begin() + x + k - cur.size(), false);
		}
	}

	cout << 0 << endl;
}


int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve();

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}