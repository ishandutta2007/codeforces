#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int nbChansons;
	cin >> nbChansons;
	vector<int> val(nbChansons);
	for (auto &v : val) cin >> v;
	set<int> enVie;
	set<int> peutSuppr;
	for (int iChanson = 0; iChanson < nbChansons; ++iChanson) 
		enVie.insert(iChanson);

	auto trouveProchaine = [](int id, const set<int> &aChercher)
	{
		if (id >= *aChercher.rbegin())
			return *aChercher.begin();
		return *aChercher.upper_bound(id);
	};

	for (int iChanson = 0; iChanson < nbChansons; ++iChanson) 
	{
		int iProchain = trouveProchaine(iChanson, enVie);
		assert(iProchain == (iChanson + 1) % nbChansons);
		if (gcd(val[iChanson], val[iProchain]) == 1)
			peutSuppr.insert(iChanson);
	}
	vector<int> suppressions;
	int dernierEcoute(-1);
	while (!peutSuppr.empty())
	{
		int nxt = trouveProchaine(dernierEcoute, peutSuppr);
		int aSuppr = trouveProchaine(nxt, enVie);
		suppressions.push_back(aSuppr+1);
		enVie.erase(aSuppr);
		peutSuppr.erase(nxt);
		if (aSuppr != nxt)
		{
			int apresAsuppr = trouveProchaine(aSuppr, enVie);
			if (peutSuppr.count(aSuppr))
				peutSuppr.erase(aSuppr);
			if (enVie.count(nxt) and gcd(val[nxt], val[apresAsuppr]) == 1)
				peutSuppr.insert(nxt);
			dernierEcoute = aSuppr;
		}
	}
	cout << suppressions.size();
	for (auto v : suppressions)
		cout << ' ' << v;
	cout << '\n';
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbTests;
	cin >> nbTests;
	for (int iTest = 0; iTest < nbTests; ++iTest) 
		solve();
}