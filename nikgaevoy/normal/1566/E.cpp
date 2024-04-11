#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


enum vert
{
	IDK, LEAVE, BUD, ROOT
};


vert dfs(vector<vector<int>> &gr, vector<vert> &types, int v)
{
	types[v] = LEAVE;

	for (auto it: gr[v])
	{
		gr[it].erase(find(gr[it].begin(), gr[it].end(), v));

		auto type = dfs(gr, types, it);

		assert(type != IDK);

		if (type == LEAVE)
			types[v] = BUD;
	}

	if (gr[v].empty())
		types[v] = LEAVE;

	return types[v];
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
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

	vector<vert> types(gr.size(), IDK);
	dfs(gr, types, 0);

	int ans = types.front() == BUD ? 0 : 1;

	types.front() = ROOT;

	ans += (int) count(types.begin(), types.end(), LEAVE) -
	       (int) count(types.begin(), types.end(), BUD);

	cout << ans << endl;
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}