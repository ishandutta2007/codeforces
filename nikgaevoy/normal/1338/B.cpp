#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	int mx = gr.size() - 1;

	for (const auto &row : gr)
	{
		int cnt = 0;

		for (auto it : row)
			if (gr[it].size() == 1)
				cnt++;

		mx -= max(0, cnt - 1);
	}

	vector<bool> col(gr.size());

	function<void(int, int)> dfs = [&gr, &col, &dfs](int v, int par)
	{
		if (par != -1)
			col[v] = !col[par];

		for (auto it : gr[v])
			if (it != par)
				dfs(it, v);
	};

	dfs(0, -1);

	vector<bool> types;
	int mn = 1;

	for (int i = 0; i < gr.size(); i++)
		if (gr[i].size() == 1)
		{
			types.push_back(col[i]);

			if (types.back() != types.front())
				mn = 3;
		}

	cout << mn << ' ' << mx << endl;
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