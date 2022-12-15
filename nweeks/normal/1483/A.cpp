#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int nbAmis, nbJours;
	cin >> nbAmis >> nbJours;
	vector<int> restants(nbAmis, (nbJours+1)/2);

	vector<vector<int>> amisPossibles(nbJours);
	for (auto &v : amisPossibles)
	{
		int nb;
		cin >> nb;
		v.resize(nb);
		for (auto &w : v)
		{
			cin >> w;
			--w;
		}
	}
	vector<int> choix(nbJours);
	for (int iJour = 0; iJour < nbJours; ++iJour) 
		if (amisPossibles[iJour].size() == 1)
		{
			int idAmis = amisPossibles[iJour][0];
			if (!restants[idAmis])
			{
				cout << "NO\n";
				return ;
			}
			--restants[idAmis];
			choix[iJour] = idAmis;
		}
	for (int iJour = 0; iJour < nbJours; ++iJour) 
		if (2 <= (int)amisPossibles[iJour].size())
		{
			int id(0);
			while (!restants[amisPossibles[iJour][id]])
				++id;
			restants[amisPossibles[iJour][id]]--;
			choix[iJour] = amisPossibles[iJour][id];
		}
	cout << "YES\n";
	for (auto v : choix)
		cout << v + 1<< ' ';
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