#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbMois;
	cin >> nbMois;
	int nbVisibles = (nbMois+1)/2;
	int nbPareils = nbMois - nbVisibles;
	vector<int> gain(nbVisibles);
	for (auto &v : gain)
		cin >> v;
	ll valPareil;
	cin >> valPareil;
	while (SZ(gain) < nbMois)
		gain.push_back(valPareil);
	vector<ll> prefixSum(nbMois+1);
	for (int i(0); i < nbMois; ++i)
		prefixSum[i+1] = prefixSum[i] + gain[i];
	vector<ll> prefixMax(nbMois+1);
	for (int i(1); i < nbMois+1; ++i)
		prefixMax[i] = max(prefixMax[i-1], prefixSum[i] - i * valPareil);
	for (int k = nbVisibles; k <= nbMois; ++k)
		if (prefixSum[k] > prefixMax[nbMois - k])
		{
			cout << k << endl;
			return 0;
		}
	cout << -1 << endl;
}