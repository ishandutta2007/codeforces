#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.first - a.second == b.first - b.second)
		return a.first < b.first;
	return a.first-a.second < b.first-b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_monstres, nb_double, nb_change;
	cin >> nb_monstres >> nb_double >> nb_change;
	nb_change = min(nb_change, nb_monstres);
	vector<pair<ll, ll> > monstres(nb_monstres);
	for (auto &[health, damage] : monstres)
		cin >> health >> damage;
	sort(monstres.rbegin(), monstres.rend(), comp);

	ll tot_dmg(0);
	for (int i(0); i < nb_monstres; ++i)
	{
		if (i < nb_change-1)
			tot_dmg += max(monstres[i].first, monstres[i].second);
		else
			tot_dmg += monstres[i].second;
	}
	ll ans = tot_dmg;
	if (nb_change==0)
	{
		cout << ans << endl;
		return 0;
	}

	for (int i(0); i < nb_monstres; ++i)
	{
		auto [health, dmg] = monstres[i];
		if (i >= nb_change - 1)
			ans = max(ans, tot_dmg - dmg + (1LL<<nb_double) * health);
		else
			ans = max(ans, tot_dmg - max(health, dmg) + (1LL<<nb_double) * health + max(0LL, monstres[nb_change-1].first - monstres[nb_change-1].second));
	}
	cout << ans << endl;
}