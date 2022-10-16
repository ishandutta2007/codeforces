#include <bits/stdc++.h>

using namespace std;

using ll = long long;


bool dfs(const vector<vector<int>> &gr, vector<int> &rp, vector<bool> &used, int v)
{
	if (used[v])
		return false;

	used[v] = true;

	for (auto it : gr[v])
		if (rp[it] == -1 || dfs(gr, rp, used, rp[it]))
		{
			rp[it] = v;

			return true;
		}

	return false;
}


void Kuhn(const vector<vector<int>> &gr, vector<int> &rp)
{
	vector<bool> matched(gr.size());

	bool flag = true;

	while (flag)
	{
		flag = false;

		vector<bool> used(gr.size());

		for (int i = 0; i < (int) gr.size(); i++)
			if (!matched[i] && dfs(gr, rp, used, i))
				matched[i] = flag = true;
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m, k;

		cin >> n >> m >> k;

		vector<pair<int, int>> edges(m);

		vector<int> deg(n);

		for (auto &it : edges)
		{
			cin >> it.first >> it.second;
			it.first--;
			it.second--;

			deg[it.first]++;
			deg[it.second]++;
		}

		if (*max_element(deg.begin(), deg.end()) > 2 * k)
		{
			for (int j = 0; j < m; j++)
				cout << "0 ";
			cout << endl;

			continue;
		}

		for (auto &it : deg)
			it = max(0, 2 * (it - k));

		vector<int> st(n);
		vector<vector<int>> gr(m);

		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			st[j] = sum;
			sum += deg[j];
		}

		for (int j = 0; j < m; j++)
		{
			for (int e = 0; e < deg[edges[j].first]; e++)
				gr[j].push_back(st[edges[j].first] + e);
			for (int e = 0; e < deg[edges[j].second]; e++)
				gr[j].push_back(st[edges[j].second] + e);
		}

		vector<int> rp(sum, -1);

		Kuhn(gr, rp);

		if (count(rp.begin(), rp.end(), -1) > 0)
		{
			for (int j = 0; j < m; j++)
				cout << "0 ";
			cout << endl;

			continue;
		}

		int trash = 100500 - 1, col = 1;
		vector<int> unp(st.size(), -1);

		for (int j = 0; j < m; j++)
		{
			auto wh = find(rp.begin(), rp.end(), j);

			if (wh == rp.end())
				cout << trash-- << ' ';
			else
			{
				int vert = (lower_bound(st.begin(), st.end(), (wh - rp.begin()) + 1) - st.begin()) - 1;

				if (unp[vert] == -1)
					cout << (unp[vert] = col++) << ' ';
				else
				{
					cout << unp[vert] << ' ';
					unp[vert] = -1;
				}
			}
		}

		cout << endl;
	}
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