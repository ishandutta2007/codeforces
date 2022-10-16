#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int up(int n)
{
	int r = 1;

	while (r < n)
		r <<= 1;

	return r;
}


class segtree
{
	vector<int> arr;

	int segmax(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return -1;
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		return max(segmax(l, r, cl, ct, 2 * v),
		           segmax(l, r, ct, cr, 2 * v + 1));
	}


public:
	segtree(const vector<int> &x) : arr(2 * up(x.size()), -1)
	{
		copy(x.begin(), x.end(), arr.begin() + arr.size() / 2);

		for (int i = arr.size() / 2 - 1; i > 0; i--)
			arr[i] = max(arr[2 * i], arr[2 * i + 1]);
	}

	int segmax(int l, int r)
	{
		return segmax(l, r, 0, arr.size() / 2, 1);
	}
};


void dfs(const vector<vector<int>> &gr, vector<int> &ans, int v, int &cur)
{
	for (auto it : gr[v])
		dfs(gr, ans, it, cur);
	ans[v] = cur++;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> nxt(n);

	for (int i = 0; i < n; i++)
	{
		auto &it = nxt[i];
		cin >> it;

		if (it == -1)
			it = i + 1;
		else
			it--;
	}

	vector<vector<int>> gr(n + 1);

	for (int i = nxt.size() - 1; i >= 0; i--)
		gr[nxt[i]].push_back(i);

	vector<int> perm(n + 1);
	int cur = 0;

	dfs(gr, perm, n, cur);

	segtree st(perm);

	for (int i = 0; i < (int) nxt.size(); i++)
		if (perm[nxt[i]] < perm[i] || st.segmax(i + 1, nxt[i]) > perm[i])
		{
			cout << -1 << endl;

			return;
		}

	perm.pop_back();
	for (auto it : perm)
		cout << it + 1 << ' ';
	cout << endl;
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
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}