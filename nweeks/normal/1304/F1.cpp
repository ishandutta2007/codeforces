#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 50;
const int MAXM = 2e4;

ll dp[MAXN][MAXM];
ll dp_start[MAXN][MAXM];
ll dp_end[MAXN][MAXM];
ll cnt_animals[MAXN][MAXM];

int nb_jours, nb_zones, taille_cam;

void init_pref(void)
{
	for (int i(0); i < nb_jours; ++i)
		for (int j(1); j < nb_zones; ++j)
			cnt_animals[i][j] += cnt_animals[i][j-1];
}

ll query(int d, int l, int r)
{
	return cnt_animals[d][r] - (l ? cnt_animals[d][l-1] : 0);	
}

ll inter(int d, int l1, int r1, int l2, int r2)
{
	int l = max(l1, l2);
	int r = min(r1, r2);
	if (l > r) return 0;

	return query(d, l, r);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nb_jours >> nb_zones >> taille_cam;

	for (int i(0); i < nb_jours; ++i)
		for (int j(0); j < nb_zones; ++j)
			cin >> cnt_animals[i][j];

	init_pref();

	for (int i(0); i < nb_jours; ++i)
	{
		for (int j(0); j + taille_cam-1 < nb_zones; ++j)
		{
			dp[i][j] = query(i, j, j + taille_cam-1);
			if (i + 1 < nb_jours)
				dp[i][j] += query(i+1, j, j + taille_cam-1);
			if (i)
			{
				ll best = 0;
				if (j - taille_cam >= 0)
					best = dp_start[i-1][j-taille_cam];
				if (j + taille_cam < nb_zones)
					best = max(best, dp_end[i-1][j+taille_cam]);
				for (int l(max(0, j - taille_cam)); l < min(nb_zones-taille_cam+1, j+taille_cam); ++l)
					best = max(best, dp[i-1][l] - inter(i, l, l+taille_cam-1, j, j+taille_cam-1));
				dp[i][j]+=best;
			}
		}
		dp_start[i][0] = dp[i][0];
		for (int j(1); j +taille_cam-1 < nb_zones; ++j)
			dp_start[i][j] = max(dp_start[i][j-1], dp[i][j]);
		dp_end[i][nb_zones-taille_cam] = dp[i][nb_zones-taille_cam];
		for (int j(nb_zones-taille_cam-1); j >= 0; --j)
			dp_end[i][j] = max(dp_end[i][j+1], dp[i][j]);
	}
	cout << dp_start[nb_jours-1][nb_zones-taille_cam] << endl;
}