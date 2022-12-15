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
		solve();
}

const int MAXN = 100;
ll grid[MAXN][MAXN];
int nb_lig, nb_col;
ll dis[MAXN][MAXN];

ll solve(void)
{
	cin >> nb_lig >> nb_col;
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
			cin>> grid[lig][col];
	ll ans = 2e18;

	for (int ligd(0); ligd < nb_lig; ++ligd)
		for (int cold(0); cold < nb_col; ++cold)
		{
			ll val_dep = grid[ligd][cold] - ligd - cold;
			if (val_dep > grid[0][0]) continue;
			dis[0][0] = grid[0][0] - val_dep;
			for (int lig(0); lig < nb_lig; ++lig)
				for (int col(0); col < nb_col; ++col)
				{
					if (lig + col == 0)
						continue;
					dis[lig][col] = 1e18;
					if (val_dep + lig + col <= grid[lig][col])
					{
						ll cost = grid[lig][col] - val_dep - lig - col;
						if (lig)
							dis[lig][col] = min(dis[lig][col], cost + dis[lig-1][col]);
						if (col)
							dis[lig][col] = min(dis[lig][col], cost + dis[lig][col-1]);
					}
				}
			ans = min(ans, dis[nb_lig-1][nb_col-1]);
		}
	cout << ans << '\n';	
	return 0;
}