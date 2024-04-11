#include <bits/stdc++.h>

using namespace std;

using ll = long long;


unsigned dfs(const vector<vector<int>> &gr, vector<unsigned> &c, int v)
{
	for (auto it : gr[v])
	{
		c[v] &= c[it];
		dfs(gr, c, it);
	}

	return c[v];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);
	vector<unsigned> c(n);

	int root = 0;

	for (int i = 0; i < gr.size(); i++)
	{
		int p;

		cin >> p >> c[i];
		p--;

		if (p >= 0)
			gr[p].push_back(i);
		else
			root = i;
	}

	dfs(gr, c, root);

	for (int i = 0; i < c.size(); i++)
		if (c[i] == 1)
			cout << i + 1 << ' ';

	if (*max_element(c.begin(), c.end()) == 0)
		cout << -1;

	cout << endl;
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