#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << (solve() ? "YES" : "NO") << '\n';
}

ll solve(void)
{
	int n;
	cin >> n;
	vector<string> grid(n);
	for (auto &s : grid)
		cin >> s;
	for (int i(0); i < n-1; ++i)
		for (int j(0); j < n-1; ++j)
			if (grid[i][j] == '1')
			{
				bool ok = false;
				if (grid[i+1][j] == '1')
					ok = true;
				if (grid[i][j+1] == '1')
					ok = true;
				if (!ok)
					return 0;
			}
	return 1;
}