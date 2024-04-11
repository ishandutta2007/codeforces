#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void gen_ans(int n, vector<int> &ans, ll l, ll r, ll &c, int pos = 0)
{
	if (c >= r || pos == n)
		return;

	auto make_move = [&c, &l, &r, &ans](int v)
	{
		if (l <= c && c < r)
			ans.push_back(v);
		c++;
	};

	if (c == 0)
	{
		assert(pos == 0);

		for (int i = 1; i < n; i++)
		{
			make_move(0);
			make_move(i);
		}

		gen_ans(n, ans, l, r, c, pos + 1);

		make_move(0);
	}
	else
	{
		const auto steps = 2 * (n - (pos + 1ll));

		if (c + steps <= l)
		{
			c += steps;
			gen_ans(n, ans, l, r, c, pos + 1);

			return;
		}

		for (int i = pos + 1; i < n; i++)
		{
			make_move(pos);
			make_move(i);
		}

		gen_ans(n, ans, l, r, c, pos + 1);
	}
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	ll l, r;

	cin >> n >> l >> r;
	l--;

	vector<int> ans;
	ll c = 0;

	gen_ans(n, ans, l, r, c);

	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << endl;

	cerr << c << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
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