#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


vector<vector<ll>> mult(const vector<vector<ll>> &a, const vector<vector<ll>> &b)
{
	vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size(), numeric_limits<ll>::max()));

	for (int i = 0; i < ret.size(); i++)
		for (int j = 0; j < ret[i].size(); j++)
			for (int k = 0; k < b.size(); k++)
				ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);

	return ret;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	assert(k % 2 == 0);

	vector<vector<ll>> matr(n, vector<ll>(n));

	for (auto &row : matr)
		for (auto &it : row)
			cin >> it;

	uniform_int_distribution<int> uid(0, 1);

	vector<bool> col(n);

	ll ans = numeric_limits<ll>::max();

	while (clock() < 2.5 * CLOCKS_PER_SEC)
	{
		do
		{
			for (int i = 1; i < col.size(); i++)
				col[i] = uid(mt) == 0;
		} while (count(col.begin(), col.end(), true) == 0);

		auto tmp = matr;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (col[i] == col[j])
					tmp[i][j] = int(1e9 + 7);

		vector<vector<ll>> q(n, vector<ll> (1, int(1e9 + 7)));
		q[0][0] = 0;

		for (int i = 0; i < k; i++)
			q = mult(tmp, q);

		ans = min(ans, q.front().front());
	}

	cout << ans << endl;
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