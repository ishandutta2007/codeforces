#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int get_kth(vector<bool> &used, int k)
{
	for (int i = 0; i < used.size(); i++)
	{
		if (!used[i])
			k--;
		if (k < 0)
			return i;
	}

	return used.size();
}


bool build(const vector<vector<int>> &gr, const vector<int> &c, vector<int> &ans, vector<bool> &used, int v)
{
	ans[v] = get_kth(used, c[v]);

	if (ans[v] == used.size())
		return false;

	used[ans[v]] = true;

	for (auto it : gr[v])
		if (!build(gr, c, ans, used, it))
			return false;

	return get_kth(used, 0) > ans[v];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);
	vector<int> c(n);
	int root = -1;

	for (int i = 0; i < n; i++)
	{
		int p;

		cin >> p >> c[i];
		p--;

		if (p == -1)
			root = i;
		else
			gr[p].push_back(i);
	}

	vector<int> ans(n);
	vector<bool> used(n);

	bool good = build(gr, c, ans, used, root);

	cout << (good ? "YES" : "NO") << endl;

	if (good)
	{
		for (auto it : ans)
			cout << it + 1 << ' ';
		cout << endl;
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