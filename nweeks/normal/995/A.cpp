#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int taille, nb_voitures;
	cin >> taille >> nb_voitures;
	vector<int> cars[4];
	for (int i(0); i < 4; ++i)
	{
		cars[i].resize(taille);
		for (int j(0); j < taille; ++j)
			cin >> cars[i][j];
	}

	vector<pair<int, int> > prochain[4];
	vector<pair<int, int> > prev[4];
	vector<pair<int, int> > park[4];
	for (int i(1); i < 3; ++i)
	{
		prochain[i].resize(taille);
		prev[i].resize(taille);
		park[i].resize(taille);
		for (int j(0); j < taille; ++j)
		{
			if (i==1)
			{
				if (j == taille-1)
					prochain[i][j] = make_pair(2, taille-1);
				else
					prochain[i][j] = make_pair(1, j+1);
				park[i][j] = make_pair(0, j);
			}
			else
			{
				if (!j)
					prochain[i][j] = make_pair(1, 0);
				else
					prochain[i][j] = make_pair(i, j-1);
				park[i][j] = make_pair(3, j);
			}
		}
	}
	for (int i(1); i < 3; ++i)
		for (int j(0); j < taille; ++j)
			prev[prochain[i][j].first][prochain[i][j].second] = make_pair(i,j);

	bool possible(false);
	for (int i(1); i < 3; ++i)
		for (int j(0); j < taille; ++j)
			possible |= !cars[i][j] or (cars[i][j] == cars[park[i][j].first][park[i][j].second]);
	if (!possible)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<tuple<int, int, int>> ops;
	for (int i(1); i < 3; ++i)
		for (int j(0); j <taille; ++j)
			if (cars[i][j] and cars[i][j] == cars[park[i][j].first][park[i][j].second])
			{
				ops.emplace_back(cars[i][j], park[i][j].first+1, park[i][j].second+1);
				cars[i][j]=0;
				--nb_voitures;
			}
	for (int i(1); i < 3; ++i)
		for (int j(0); j < taille; ++j)
			if (cars[i][j] and !cars[prochain[i][j].first][prochain[i][j].second])
			{
				 while (nb_voitures > 0)
				 {
				 	auto [pi, pj] = park[i][j];
				 	auto [ni, nj] = prochain[i][j];
				 	if (cars[i][j])
				 	{
				 		if (cars[pi][pj] == cars[i][j])
				 		{
				 			ops.emplace_back(cars[i][j], pi+1, pj+1);
				 			cars[i][j] = 0;
				 			--nb_voitures;
				 		}
				 		else
				 		{
				 			ops.emplace_back(cars[i][j], ni+1, nj+1);
				 			cars[ni][nj] = cars[i][j];
				 			cars[i][j] = 0;	
				 		}
				 	}
				 	auto [ai, aj] = prev[i][j];
				 	i=ai, j = aj;
				 }
				 cout << SZ(ops) << endl;
				 for (auto [i, j, k] : ops)
				 	cout << i << ' ' << j << ' ' << k << '\n';
				return 0;
			}

	cout << SZ(ops) << endl;
	for (auto [i, j, k] : ops)
		cout << i << ' ' << j << ' ' << k << '\n';
}