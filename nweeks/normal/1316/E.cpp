#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e5+1;;
const int MAXP = 7;
ll dp[MAXN][(1<<MAXP)];

struct Joueur
{
	ll spec;
	vector<ll> scores;
	int id;

	bool operator<(Joueur o) const
	{
		if (spec == o.spec) return id < o.id;
		return spec < o.spec;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_joueurs, a_prendre, nb_audiences;	
	cin >> nb_joueurs >> a_prendre >> nb_audiences;

	vector<Joueur> joueurs(nb_joueurs);
	for (int i(0); i < nb_joueurs; ++i)
	{
		joueurs[i].id = i;
		cin >> joueurs[i].spec;
	}
	for (int i(0); i < nb_joueurs; ++i)
	{
		joueurs[i].scores.resize(a_prendre);
		for (auto &v : joueurs[i].scores)
			cin >> v;
	}
	sort(joueurs.rbegin(), joueurs.rend());

	for (int i(0); i <= nb_joueurs; ++i)
		for (int mask(0); mask < (1<<a_prendre); ++mask)
			dp[i][mask] = -1;
	dp[0][0] = 0;
	for (int i(0); i < nb_joueurs; ++i)
		for (int mask(0); mask < (1<<a_prendre); ++mask)
			if (dp[i][mask] != -1)
			{
				int selec = __builtin_popcount(mask);
				int dans_gradins = i - selec;
				if (dans_gradins < nb_audiences)
					dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask] + joueurs[i].spec);
				else
					dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]);
				for (int pos(0); pos < a_prendre; ++pos)
					if (((1<<pos)&mask) == 0)
						dp[i+1][mask + (1<<pos)] = max(dp[i+1][mask + (1<<pos)], dp[i][mask] + joueurs[i].scores[pos]);
			}
	cout << dp[nb_joueurs][(1<<a_prendre)-1] << endl;;
}