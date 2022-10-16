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

	int segmin(int l, int r, int cl, int cr, int v) const
	{
		if (r <= cl || cr <= l)
			return numeric_limits<int>::max();
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		return min(segmin(l, r, cl, ct, 2 * v),
		           segmin(l, r, ct, cr, 2 * v + 1));
	}

public:
	segtree(const vector<int> &qw) : arr(2 * up(qw.size()), numeric_limits<int>::max())
	{
		copy(qw.begin(), qw.end(), arr.begin() + arr.size() / 2);

		for (int i = arr.size() / 2 - 1; i > 0; i--)
			arr[i] = min(arr[2 * i], arr[2 * i + 1]);
	}

	int segmin(int l, int r) const
	{
		return segmin(l, r, 0, arr.size() / 2, 1);
	}
};


void dfs (const vector<vector<int>> &ljmp, vector<bool> &used, vector<int> &longrjmp, int i, int siz, vector<int> &path)
{
	if (used[i])
		return;
	used[i] = true;

	path.push_back(i);

	if (path.size () >= siz)
		longrjmp[i] = path[path.size () - siz];

	for (auto it : ljmp[i])
		dfs (ljmp, used, longrjmp, it, siz, path);

	path.pop_back();
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, q;

	cin >> n >> m >> q;

	vector<int> perm(n), arr(m);

	for (auto &it : perm)
	{
		cin >> it;
		it--;
	}

	for (auto &it : arr)
	{
		cin >> it;
		it--;
	}

	vector<int> nxt(perm.size());

	for (int i = 0; i < perm.size(); i++)
		nxt[perm[i]] = perm[(i + 1) % perm.size()];

	vector<int> rjmp(m, -1), longrjmp(m, numeric_limits<int>::max());
	vector<int> lst(perm.size(), -1);

	vector<vector<int>> ljmp(m);

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		rjmp[i] = lst[nxt[arr[i]]];
		if (rjmp[i] != -1)
			ljmp[rjmp[i]].push_back (i);
		lst[arr[i]] = i;
	}

	vector<bool> used(m);
	vector<int> path;

	for (int i = arr.size() - 1; i >= 0; i--)
		dfs (ljmp, used, longrjmp, i, perm.size (), path);

#ifdef LOCAL
	for (auto it : nxt)
		cout << it << ' ';
	cout << endl;
	for (auto it : rjmp)
		cout << it << ' ';
	cout << endl;
	for (auto it : longrjmp)
		cout << it << ' ';
	cout << endl;
#endif

	segtree st(longrjmp);

	string ans(q, '0');

	for (int i = 0; i < q; i++)
	{
		int l, r;

		cin >> l >> r;
		l--;

		if (st.segmin(l, r) < r)
			ans[i] = '1';
	}

	cout << ans << endl;
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