#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int nbPath, nbCour;
	cin >> nbPath >> nbCour;
	vector<vector<int>> costs(nbPath, vector<int>(nbCour));
	for (int i = 0; i < nbPath; ++i) 
		for (int j = 0; j < nbCour; ++j) 
			cin >> costs[i][j];
	vector<pair<int, int>> possibles;
	for (int i(0); i < nbPath; ++i)
		for (int j(0); j < nbCour; ++j)
			possibles.emplace_back(i, j);

	sort(possibles.begin(), possibles.end(),
			[&](pair<int, int> lhs, pair<int, int> rhs)
			{
			return costs[lhs.first][lhs.second]
			< costs[rhs.first][rhs.second];
			});

	vector<vector<int>> sol(nbPath, vector<int>(nbCour, -1));

	for (int i(0); i < nbCour; ++i)
	{
		auto [p, c] = possibles[i];
		sol[p][i] = c;
	}

	for (int i(0); i < nbPath; ++i)
	{
		set<int> restant;
		for (int j(0); j < nbCour; ++j)
			restant.insert(j);
		for (int j(0); j < nbCour; ++j)
			if (sol[i][j] != -1)
				restant.erase(sol[i][j]);
		for (int j(0); j < nbCour; ++j)
			if (sol[i][j] == -1)
			{
				sol[i][j] = *restant.begin();
				assert(sol[i][j] != -1);
				restant.erase(sol[i][j]);
			}
		assert(restant.empty());
	}
	for (int i(0); i < nbPath; ++i)
	{
		for (auto v : sol[i])
		{
			assert(v != -1);
			cout << costs[i][v] << ' ';
		}
		cout << '\n';
	}
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}