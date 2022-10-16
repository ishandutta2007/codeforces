#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(time(0));

const ll add[] = {37, 51, 99, 129, 183, 259};
ll mod = 1e13;


ll vh(const vector<int> &arr, int n)
{
	ll h = 0;

	for (auto it : arr)
	{
		h *= n;
		h %= mod;
		h += it;
	}

	return h;
}


vector<int> z_function(const vector<ll> &s)
{
	int n = (int) s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	mod += add[mt() % 6];

	int n, m;

	cin >> n >> m;

	vector<vector<int>> arr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		arr[a].push_back((b + n - a) % n);
		arr[b].push_back((a + n - b) % n);
	}

	for (auto &row : arr)
		sort(row.begin(), row.end());

	vector<ll> hs(n);

	for (int i = 0; i < (int) arr.size(); i++)
		hs[i] = vh(arr[i], n);

	for (int i = 0; i < n; i++)
		hs.push_back(hs[i]);

	auto q = z_function(hs);

	for (int i = 1; i < n; i++)
		if (q[i] == (int) hs.size() - i)
		{
			cout << "Yes" << endl;

			return;
		}

	cout << "No" << endl;
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