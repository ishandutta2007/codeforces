#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e3+1;
const int MAXC = 1e4+1;

ll dp[MAXN][MAXC]; // Max mana you have when reaching ..

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll nb_nids, capacite_init, augmentation, refill;
	cin >> nb_nids >> capacite_init >> augmentation >> refill;

	vector<ll> nb_oiseaux(nb_nids), cost(nb_nids);

	for (auto &v : nb_oiseaux)
		cin >> v;
	for (auto &v : cost)
		cin >> v;

	for (int i(0); i < MAXN; ++i)
		for (int j(0); j < MAXC; ++j)
			dp[i][j] = -1;

	dp[0][0] = capacite_init;
	for (int nid(0); nid < nb_nids; ++nid)
		for (int sacrifies(0); sacrifies< MAXC; ++sacrifies)
			if (dp[nid][sacrifies] >= 0)
				for (int nb_pris(0); nb_pris <= nb_oiseaux[nid]; ++nb_pris)
					if (dp[nid][sacrifies] - cost[nid] * nb_pris >= 0)
					{
						ll capacite = capacite_init + (sacrifies + nb_pris) * augmentation;
						dp[nid+1][sacrifies + nb_pris] = max(dp[nid+1][sacrifies+nb_pris], 
															min(capacite, dp[nid][sacrifies] - nb_pris*cost[nid] + refill));
					}
	for (int nb_oiseaux(MAXC-1); nb_oiseaux>= 0; --nb_oiseaux)
		if (dp[nb_nids][nb_oiseaux] >= 0)
		{
			cout << nb_oiseaux << endl;
			return 0;
		}
}