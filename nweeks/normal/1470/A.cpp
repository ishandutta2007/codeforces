#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

ll solve(void)
{
	int nbAmis, nbCadeaux;
	cin >> nbAmis >> nbCadeaux;
	vector<int> amis(nbAmis);
	for (auto &v : amis)
	{
		cin >> v; --v;
	}
	vector<ll> cadeaux(nbCadeaux);
	for (auto &v : cadeaux)
		cin >> v;
	sort(amis.begin(), amis.end());
	vector<ll> prefCadeaux(nbCadeaux+1), prefAmis(nbAmis+1);
	for (int i(0); i < nbCadeaux; ++i)
		prefCadeaux[i+1] = prefCadeaux[i] + cadeaux[i];
	for (int i(0); i < nbAmis; ++i)
		prefAmis[i+1] = prefAmis[i] + cadeaux[amis[i]];
	ll cost(1e18);
	for (int take(0); take <= min(nbCadeaux, nbAmis); ++take)
		cost = min(cost, prefCadeaux[take] + prefAmis[nbAmis - take]);
	return cost;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	cout << solve() << '\n';
}