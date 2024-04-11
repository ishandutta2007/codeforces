#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int nbSommets;
		cin >> nbSommets;
		vector<ll> weights(nbSommets);
		vector<int> deg(nbSommets);
		for (auto &v : weights)
			cin >> v;
		for (int i(1); i < nbSommets; ++i)
		{
			int u, v;
			cin >> u >> v;
			--u, --v;
			deg[u]++;
			deg[v]++;
		}
		vector<ll> have;
		for (int u(0); u < nbSommets; ++u)
			while (deg[u]-- > 1)
				have.push_back(weights[u]);

		sort(have.rbegin(), have.rend());
		ll cur(0);
		for (auto v : weights)
			cur += v;
		for (int i(0); i < nbSommets-1; ++i)
		{
			cout << cur << ' ';
			if (i < SZ(have))
				cur += have[i];
		}
		cout << '\n';
	}
}