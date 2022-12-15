#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll nb_pil, monte, descend, echange;
	cin >> nb_pil >> monte >> descend >> echange;

	ll ans = 2e18;
	vector<ll> h(nb_pil);
	for (auto &v : h)
		cin >> v;

	ll sum_bef(0), sum_aft(0);
	sort(h.begin(), h.end());
	for (auto v : h)
		sum_aft += v;
	for (int i(0); i < nb_pil; ++i)
	{
		sum_aft -= h[i];
		sum_bef += h[i];

		int nb_avant = i+1;
		int nb_apres = nb_pil - nb_avant;
		ll nb_monte_gauche = nb_avant * h[i] - sum_bef;
		ll nb_descend_gauche= sum_aft - nb_apres * h[i];
		if (i == nb_pil-1)
		{
			ans = min(ans, monte * nb_monte_gauche);
			continue ;
		}
		if (h[i+1] == h[i]) continue;
		ll nb_monte_droite = nb_avant * (h[i+1] - 1) - sum_bef;
		ll nb_descend_droite = sum_aft - nb_apres * (h[i+1]-1);
		ans = min({ans, descend * nb_descend_gauche+ monte * nb_monte_gauche, descend*nb_descend_droite + monte* nb_monte_droite});


		if (nb_monte_gauche < nb_descend_gauche)
		{
			if ( nb_monte_droite - nb_descend_droite> 0)
			{
				ll split = (sum_aft + sum_bef - nb_pil * h[i])/nb_pil;
				ll nb_monte = nb_avant * (h[i]+split) - sum_bef;
				ll nb_descend = sum_aft - nb_apres * (h[i] + split);
				ans = min(ans, echange * nb_monte + descend * (nb_descend - nb_monte));
				if (split + 1 < h[i+1])
				{
					nb_monte += nb_avant;
					nb_descend -= nb_apres;
					assert(nb_monte > nb_descend);
					ans = min(ans, echange * nb_descend + monte * (nb_monte - nb_descend));
				}
				ans = min({ans, echange * (nb_monte_gauche) + descend * (nb_descend_gauche - nb_monte_gauche),
								echange * (nb_descend_droite) + monte * (nb_monte_droite - nb_descend_droite)});
			}
			else
			{
				ans = min({ans, echange * nb_monte_gauche + descend * (nb_descend_gauche - nb_monte_gauche)
						, echange * nb_monte_droite+ descend* (nb_descend_droite- nb_monte_droite)});		
			}
		}
		else
		{
			ans = min({ans, echange * nb_descend_gauche + monte*(nb_monte_gauche - nb_descend_gauche)
							, echange * nb_descend_droite + monte * (nb_monte_droite - nb_descend_droite)});
		}
	}
	assert(ans >= 0);
	cout << ans << endl;
}