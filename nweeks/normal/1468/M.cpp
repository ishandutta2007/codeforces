#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

map<int, int> hsh;
int nbTot;

void change(int &x)
{
	if (!hsh.count(x))
		hsh[x] = nbTot++;
	x = hsh[x];
}

ll sq(ll x) { return x * x; }

void solve(void)
{
	hsh.clear();
	nbTot=0;
	int nbEnsembles;
	cin >> nbEnsembles;
	vector<vector<int>> ensembles(nbEnsembles);
	for (auto &v : ensembles)
	{
		int taille;
		cin >> taille;
		v.resize(taille);
		for (auto &w : v)
		{
			cin >> w;
			change(w);
		}
	}
	vector<bool> inside(nbTot);
	for (int i(0); i < nbEnsembles; ++i)
		if (sq(SZ(ensembles[i])) > nbTot)
		{
			for (auto v : ensembles[i])
				inside[v] = true;
			
			for (int j(0); j < nbEnsembles; ++j)
				if (j > i or sq(SZ(ensembles[j])) <= nbTot)
				{
					int c(0);
					for (auto v : ensembles[j])
						c += inside[v];
					if (c >= 2)
					{
						cout << i+1 << ' ' << j+1 << endl;
						return ;
					}
				}

			for (auto v : ensembles[i])
				inside[v] = false;
		}

	vector<vector<pair<int, int>>> vus(nbTot);
	for (int i(0); i < nbEnsembles; ++i)
		if (sq(SZ(ensembles[i])) <= nbTot)
			for (int j(0); j < SZ(ensembles[i]); ++j)
				for (int k(j+1); k < SZ(ensembles[i]); ++k)
				{
					int a(ensembles[i][j]), b(ensembles[i][k]);
					if (a > b) swap(a, b);
					vus[a].emplace_back(b, i);
				}
	vector<int> mark(nbTot, -1);
	for (int i(0); i < nbTot; ++i)
	{
		for (auto p : vus[i])
		{
			if (mark[p.first] != -1)
			{
				cout << 1 + mark[p.first] << ' ' << 1 + p.second << '\n';
				return ;
			}
			mark[p.first] = p.second;
		}
		for (auto p : vus[i])
			mark[p.first] = -1;
	}
	cout << -1 << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}